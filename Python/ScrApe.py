r"""
ScrApe.py — ScrApe: bulk web article → Obsidian markdown clipper

              __,__
     .--.  .-"     "-.  .--.
    / .. \/  .-. .-.  \/ .. \
   | |  '|  /   Y   \  |'  | |
   | \   \  \ 0 | 0 /  /   / |
    \ '- ,\.-"`` ``"-./, -' /
     `'-' /_   ^ ^   _\ '-'`
         |  \._   _./  |
         \   \ `~` /   /
          '._ '-=-' _.'
             '~---~'
                          🍌 ScrApe!

ScrApe swings through the web, grabs pages by the fistful, and
peels them into tasty Obsidian-compatible markdown clippings.
Knows three banana flavours: Wikipedia, GoodReads, and Default.

Usage — let the ape loose:
    # Feed ape a bunch of URLs from a file
    python ScrApe.py -i urls.txt -o E:\\vault\\Clippings

    # Point ape at specific trees
    python ScrApe.py -o ./output --urls https://en.wikipedia.org/wiki/Ecotone https://paulgraham.com/love.html

    # Let ape sniff before grabbing (dry run)
    python ScrApe.py -i urls.txt -o ./output --dry-run --limit 5

    # Pocket-export mode: ape reads your Pocket bookmarks and
    # scribbles notes back into the file after grabbing
    python ScrApe.py -i pocket.md -o E:\\vault\\Clippings\\Pocket --annotate-source

    # Unleash the whole troop (parallel, default 10 apes)
    python ScrApe.py -i urls.txt -o ./output --workers 10

    # One careful ape only
    python ScrApe.py -i urls.txt -o ./output --workers 1

    # Pipe bananas from another command
    some_command | python ScrApe.py -o ./output --stdin

    # Ape smash existing files and re-grab
    python ScrApe.py -i urls.txt -o ./output --overwrite
"""

import argparse
import json
import os
import re
import sys
import threading
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime
from urllib.parse import urlparse

import html2text
import requests
from bs4 import BeautifulSoup

# ── Constants ──────────────────────────────────────────────────────────────
TODAY = datetime.now().strftime("%Y-%m-%d")

BROWSER_HEADERS = {
    "User-Agent": (
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
        "AppleWebKit/537.36 (KHTML, like Gecko) "
        "Chrome/126.0.0.0 Safari/537.36"
    ),
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
    "Accept-Language": "en-US,en;q=0.9",
    "Accept-Encoding": "gzip, deflate, br",
    "DNT": "1",
    "Connection": "keep-alive",
    "Upgrade-Insecure-Requests": "1",
    "Sec-Fetch-Dest": "document",
    "Sec-Fetch-Mode": "navigate",
    "Sec-Fetch-Site": "none",
    "Sec-Fetch-User": "?1",
    "Cache-Control": "max-age=0",
}

# Site suffixes commonly appended to <title> that should be stripped
TITLE_SUFFIXES = [
    "Quanta Magazine", "The Atlantic", "Vox", "The Guardian", "Salon",
    "Medium", "Inc\\.com", "Scientific American", "BBC", "Forbes",
    "Bloomberg", "Wait But Why", "The New York Times", "The Verge",
    "Wired", "Ars Technica", "The Washington Post", "NPR", "Reuters",
    "New Yorker", "Hacker News", "Lifehacker", "Gizmodo", "Slate",
    "The Hindu", "DW", "LiveMint",
]

# File extensions that indicate non-article resources
SKIP_EXTENSIONS = r"\.(jpg|jpeg|png|gif|svg|webp|pdf|mp3|mp4|zip|tar|gz)(\?.*)?$"

REQUEST_TIMEOUT = 30
DEFAULT_DELAY = 1.5  # seconds between requests (per-domain cooldown)
DEFAULT_WORKERS = 10

# ── Thread safety ──────────────────────────────────────────────────────────
_print_lock = threading.Lock()
_domain_locks: dict[str, threading.Lock] = {}   # per-domain locks
_domain_last: dict[str, float] = {}             # per-domain last-request timestamp
_domain_meta_lock = threading.Lock()            # protects the two dicts above


def _safe_print(*args, **kwargs):
    """Thread-safe ooh-ooh to stdout."""
    with _print_lock:
        print(*args, **kwargs)


def _domain_wait(url: str, delay: float):
    """Ape waits politely between grabs from the same tree."""
    host = (urlparse(url).hostname or "unknown").lower()
    with _domain_meta_lock:
        if host not in _domain_locks:
            _domain_locks[host] = threading.Lock()
            _domain_last[host] = 0.0
        lock = _domain_locks[host]

    with lock:
        elapsed = time.monotonic() - _domain_last[host]
        if elapsed < delay:
            time.sleep(delay - elapsed)
        _domain_last[host] = time.monotonic()


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Utilities
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def detect_template(url: str) -> str:
    """Sniff the URL to pick the right banana flavour."""
    host = (urlparse(url).hostname or "").lower()
    if re.search(r"(^|\.)wikipedia\.org$", host):
        return "wikipedia"
    if re.search(r"(^|\.)goodreads\.com$", host):
        return "goodreads"
    return "default"


def sanitize_filename(name: str) -> str:
    """Make a string safe for use as a Windows/Mac/Linux filename."""
    name = re.sub(r'[<>:"/\\|?*\x00-\x1f]', "", name)
    name = name.strip(". ")
    return name[:200].strip() if len(name) > 200 else name


def clean_title(title: str) -> str:
    """Strip common site-name suffixes from page titles."""
    pattern = r"\s*[|\u2013\u2014\-]\s*(" + "|".join(TITLE_SUFFIXES) + r").*$"
    return re.sub(pattern, "", title, flags=re.I).strip()


def make_converter() -> html2text.HTML2Text:
    """Create a configured HTML-to-Markdown converter."""
    h = html2text.HTML2Text()
    h.body_width = 0          # no line wrapping
    h.protect_links = True
    h.wrap_links = False
    h.unicode_snob = True
    h.skip_internal_links = False
    h.inline_links = True
    h.ignore_emphasis = False
    h.ignore_images = False
    h.ignore_tables = False
    h.ignore_links = False
    return h


def resolve_links(tag, base_url: str):
    """Convert relative hrefs and srcs to absolute URLs in-place."""
    for a in tag.find_all("a", href=True):
        if a["href"].startswith("/"):
            a["href"] = base_url + a["href"]
    for img in tag.find_all("img", src=True):
        src = img["src"]
        if src.startswith("//"):
            img["src"] = "https:" + src
        elif src.startswith("/"):
            img["src"] = base_url + src


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Fetch
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def fetch_page(url: str, session: requests.Session) -> tuple[requests.Response | None, str | None]:
    """Swing out and grab a page. If the branch looks thin, try a sneakier grab."""
    try:
        resp = session.get(url, timeout=REQUEST_TIMEOUT, allow_redirects=True)
        resp.raise_for_status()

        # If the page is suspiciously small or lacks a <title>, retry with minimal headers
        if len(resp.text) < 2000 or "<title" not in resp.text.lower():
            minimal = {"User-Agent": "Mozilla/5.0 (compatible)"}
            resp2 = requests.get(url, headers=minimal, timeout=REQUEST_TIMEOUT, allow_redirects=True)
            resp2.raise_for_status()
            if len(resp2.text) > len(resp.text):
                resp = resp2

        return resp, None
    except requests.exceptions.TooManyRedirects:
        return None, "Too many redirects"
    except requests.exceptions.ConnectionError as e:
        return None, f"Connection error"
    except requests.exceptions.Timeout:
        return None, "Request timed out"
    except requests.exceptions.HTTPError as e:
        code = e.response.status_code if e.response is not None else "?"
        return None, f"HTTP {code}"
    except Exception as e:
        return None, str(e)


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Metadata extraction
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def extract_meta(soup: BeautifulSoup, url: str) -> dict:
    """Pull title, description, author, published from <meta> / JSON-LD."""
    meta = {}

    # Title: prefer og:title, fall back to <title>, then URL path
    og = soup.find("meta", property="og:title")
    tt = soup.find("title")
    raw_title = (
        (og["content"].strip() if og and og.get("content") else "")
        or (tt.get_text(strip=True) if tt else "")
        or urlparse(url).path.rstrip("/").split("/")[-1]
    )
    # If title still looks like a URL slug, try harder
    if re.match(r"^[\w-]+\.\w+$", raw_title) and tt:
        raw_title = tt.get_text(strip=True) or raw_title
    meta["title"] = raw_title

    # Description
    og_d = soup.find("meta", property="og:description")
    mt_d = soup.find("meta", attrs={"name": "description"})
    meta["description"] = (
        (og_d["content"].strip() if og_d and og_d.get("content") else "")
        or (mt_d["content"].strip() if mt_d and mt_d.get("content") else "")
        or ""
    )

    # Author
    for src in [
        soup.find("meta", attrs={"name": "author"}),
        soup.find("meta", property="article:author"),
        soup.find("meta", attrs={"name": "byl"}),  # NYT byline
    ]:
        if src and src.get("content"):
            val = src["content"].strip()
            if not val.startswith("http"):
                meta["author"] = val
                break
    # Try JSON-LD author
    if "author" not in meta:
        for s in soup.find_all("script", type="application/ld+json"):
            txt = s.string or ""
            m = re.search(r'"author"[^}]*"name"\s*:\s*"([^"]+)"', txt)
            if m:
                meta["author"] = m.group(1)
                break
    meta.setdefault("author", "")

    # Published date
    for prop in ["article:published_time", "datePublished", "date",
                 "article:published", "publishdate", "sailthru.date"]:
        tag = soup.find("meta", property=prop) or soup.find("meta", attrs={"name": prop})
        if tag and tag.get("content"):
            ds = tag["content"].strip()[:10]
            if re.match(r"\d{4}-\d{2}-\d{2}", ds):
                meta["published"] = ds
                break
    if "published" not in meta:
        for s in soup.find_all("script", type="application/ld+json"):
            m = re.search(r'"datePublished"\s*:\s*"(\d{4}-\d{2}-\d{2})', s.string or "")
            if m:
                meta["published"] = m.group(1)
                break
    meta.setdefault("published", "")

    return meta


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Template: Wikipedia
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def clip_wikipedia(url: str, soup: BeautifulSoup) -> tuple[str, str]:
    """Returns (filename, markdown_content) for a Wikipedia article."""
    parsed = urlparse(url)
    base = f"{parsed.scheme}://{parsed.hostname}"
    meta = extract_meta(soup, url)

    # Title from heading
    h = soup.find(id="firstHeading")
    title = h.get_text(strip=True) if h else meta["title"]
    title = re.sub(r"\s*[-–—]\s*Wikipedia.*$", "", title)

    # Main content
    div = soup.find(id="mw-content-text")
    if div:
        # Remove noise elements per Obsidian Web Clipper template config
        for sel in [".navbox", ".printfooter", ".side-box", ".mw-editsection",
                    ".reference", ".reflist", ".sistersitebox", ".noprint",
                    ".mw-empty-elt", ".toc", ".mbox-small", ".ambox",
                    ".metadata", ".hatnote"]:
            for t in div.select(sel):
                t.decompose()
        resolve_links(div, base)
        html = str(div)
    else:
        html = str(soup)

    md = make_converter().handle(html).strip()

    # Aliases from first-paragraph bold text
    aliases = []
    fp = div.find("p") if div else None
    if fp:
        for b in fp.find_all("b"):
            alt = b.get_text(strip=True)
            if alt and alt.lower() != title.lower():
                aliases.append(alt)

    fm = f'---\ntitle: "{title}"\nsource: "{url}"\npublished: {meta["published"]}\n'
    fm += f"template version: 1.1\ncreated: {TODAY}\ndescription:\ntags:\n"
    fm += '  - "clippings"\n  - "wikipedia"\n  - "todo"\n'
    if aliases:
        fm += "aliases:\n"
        for a in aliases[:5]:
            fm += f'  - "{a}"\n'
    fm += "---\n"

    return sanitize_filename(title), fm + md


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Template: GoodReads
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def clip_goodreads(url: str, soup: BeautifulSoup) -> tuple[str, str]:
    """Returns (filename, markdown_content) for a GoodReads book page."""
    meta = extract_meta(soup, url)
    raw_title = meta["title"]
    fn_title = re.sub(r"\s*\(.*?#\d+\)", "", raw_title)

    og_img = soup.find("meta", property="og:image")
    cover = og_img["content"].strip() if og_img and og_img.get("content") else ""

    author = meta["author"]
    if not author:
        for s in soup.find_all("script", type="application/ld+json"):
            m = re.search(r'"author".*?"name"\s*:\s*"([^"]+)"', s.string or "")
            if m:
                author = m.group(1)
                break

    rating = ""
    for s in soup.find_all("script", type="application/ld+json"):
        m = re.search(r'"ratingValue"\s*:\s*"?(\d+\.?\d*)"?', s.string or "")
        if m:
            rating = m.group(1)
            break

    pages_tag = soup.select_one('[itemprop="numberOfPages"]')
    pages = re.sub(r"[^\d]", "", pages_tag.get_text()) if pages_tag else ""

    lang = "English"
    for dt in soup.find_all("dt"):
        if "language" in dt.get_text(strip=True).lower():
            dd = dt.find_next_sibling("dd")
            if dd:
                lang = dd.get_text(strip=True)
                break

    fm = f"""---
title: "{raw_title}"
subtitle:
series:
author:
  - "[[{author}]]"
book cover: {cover}
source: {url}
language: {lang}
published: {meta['published']}
description: {meta['description']}
pages: {pages}
awards:
rating: "{rating}"
created: {TODAY}
template version: 2.2
genres:
tags:
  - todo
  - book
owned:
availability:
format:
started: {TODAY}
finished: {TODAY}
notes written: false
review:
score:
---
"""
    body = f"![Book Cover]({cover})\n# {raw_title}\n\n## Thoughts & Notes\n"
    return sanitize_filename(fn_title), fm + body


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Template: Default article
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def clip_default(url: str, soup: BeautifulSoup) -> tuple[str, str]:
    """Returns (filename, markdown_content) for a generic web article."""
    parsed = urlparse(url)
    base = f"{parsed.scheme}://{parsed.hostname}"
    meta = extract_meta(soup, url)
    title = clean_title(meta["title"])

    # Find article body using common selectors (ordered by specificity)
    article = (
        soup.find("article")
        or soup.find(class_="post-content")
        or soup.find(class_="article-body")
        or soup.find(class_="entry-content")
        or soup.find(class_="post-body")
        or soup.find(id="article-body")
        or soup.find(role="main")
        or soup.find("main")
    )

    if article:
        resolve_links(article, base)
        content_html = str(article)
    else:
        # Fallback: clean body
        body = soup.find("body")
        if body:
            for tn in ["nav", "header", "footer", "script", "style",
                        "noscript", "aside", "iframe"]:
                for t in body.find_all(tn):
                    t.decompose()
            for cls in ["sidebar", "navigation", "nav", "menu", "footer",
                        "header", "cookie", "banner", "advertisement", "ad",
                        "social-share", "related-posts", "comments"]:
                for t in body.find_all(class_=re.compile(cls, re.I)):
                    t.decompose()
            resolve_links(body, base)
            content_html = str(body)
        else:
            content_html = str(soup)

    md = make_converter().handle(content_html).strip()

    # Author as YAML wikilinks
    author = meta["author"]
    if author:
        parts = [a.strip() for a in re.split(r",\s*|\s+and\s+", author) if a.strip()]
        author_block = "author:\n" + "\n".join(f'  - "[[{a}]]"' for a in parts)
    else:
        author_block = "author:"

    fm = f"""---
title: "{title}"
source: {url}
{author_block}
published: {meta['published']}
template version: 1.0
created: {TODAY}
description: {meta['description']}
tags:
  - clippings
---
"""
    return sanitize_filename(title), fm + md


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Input parsing
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def parse_urls_from_file(path: str) -> list[str]:
    """Extract URLs from a text/markdown file (one URL per line, ignores other lines)."""
    urls = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if line.startswith("http://") or line.startswith("https://"):
                urls.append(line)
    return urls


def annotate_source_file(path: str, results: list[dict]):
    """Add wikilink / failure annotations next to URLs in the source file."""
    with open(path, "r", encoding="utf-8") as f:
        lines = f.readlines()

    lookup = {r["url"]: r for r in results}
    out = []
    i = 0
    while i < len(lines):
        line = lines[i].rstrip("\n")
        stripped = line.strip()

        if stripped in lookup:
            out.append(line)
            # Skip past any existing annotation
            j = i + 1
            while j < len(lines) and lines[j].strip() == "":
                j += 1
            has_annotation = (
                j < len(lines)
                and (lines[j].strip().startswith("→ ") or lines[j].strip().startswith("⚠️"))
            )
            if not has_annotation:
                r = lookup[stripped]
                if r["success"]:
                    out.append(f'→ [[{r["filename"]}]] ✅')
                else:
                    out.append(f'⚠️ FAILED: {r["error"]}')
        else:
            out.append(line)
        i += 1

    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(out))


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Summary table
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def generate_summary_table(results: list[dict], path: str):
    """Write a markdown file with a summary table of clipped + failed URLs."""
    ok = [r for r in results if r["success"]]
    fail = [r for r in results if not r["success"]]

    lines = [
        "# ScrApe — Loot Report",
        "",
        f"Run date: **{TODAY}**",
        f"Processed: **{len(results)}** · Succeeded: **{len(ok)}** · Failed: **{len(fail)}**",
        "",
    ]

    if ok:
        lines.append(f"## Clipped ({len(ok)})")
        lines.append("")
        lines.append("| # | Clipping | Source | Template |")
        lines.append("|---|----------|--------|----------|")
        for i, r in enumerate(ok, 1):
            host = (urlparse(r["url"]).hostname or "").lower()
            for prefix in ("www.", "m.", "mobile.", "en."):
                if host.startswith(prefix):
                    host = host[len(prefix):]
            link = "[[" + r["filename"] + "]]"
            lines.append(f"| {i} | {link} | {host} | {r['template']} |")
        lines.append("")

    if fail:
        lines.append(f"## Failed ({len(fail)})")
        lines.append("")
        lines.append("| # | URL | Error |")
        lines.append("|---|-----|-------|")
        for i, r in enumerate(fail, 1):
            lines.append(f"| {i} | {r['url']} | {r['error']} |")
        lines.append("")

    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Core processor
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def process_url(url: str, outdir: str, session: requests.Session | None = None,
                dry_run: bool = False, overwrite: bool = False,
                delay: float = DEFAULT_DELAY) -> dict:
    """One ape, one banana. Grab, peel, save. Returns the loot report."""
    result = {"url": url, "success": False, "filename": "", "error": "", "template": ""}

    template = detect_template(url)
    result["template"] = template

    # Skip binary / non-article URLs
    if re.search(SKIP_EXTENSIONS, urlparse(url).path, re.I):
        result["error"] = "Non-article resource, skipped"
        return result

    _safe_print(f"  🍌 Grabbing: {url}")

    if session is None:
        session = requests.Session()
        session.headers.update(BROWSER_HEADERS)

    _domain_wait(url, delay)
    resp, err = fetch_page(url, session)
    if err:
        result["error"] = err
        _safe_print(f"    💀 {err}")
        return result

    soup = BeautifulSoup(resp.text, "html.parser")

    try:
        if template == "wikipedia":
            filename, content = clip_wikipedia(url, soup)
        elif template == "goodreads":
            filename, content = clip_goodreads(url, soup)
        else:
            filename, content = clip_default(url, soup)
    except Exception as e:
        result["error"] = f"Parse error: {e}"
        _safe_print(f"    💀 {e}")
        return result

    if not filename:
        result["error"] = "Could not determine title"
        _safe_print(f"    💀 No title")
        return result

    result["filename"] = filename

    if dry_run:
        result["success"] = True
        _safe_print(f"    🙊 [DRY] {filename}.md ({template})")
        return result

    filepath = os.path.join(outdir, filename + ".md")
    if os.path.exists(filepath) and not overwrite:
        result["success"] = True
        _safe_print(f"    🙈 Already got: {filename}.md")
        return result

    os.makedirs(outdir, exist_ok=True)
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)

    result["success"] = True
    _safe_print(f"    🍌 {filename}.md ({template})")
    return result


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  CLI
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="ScrApe",
        description="ScrApe — an ape that swings through the web and peels pages into Obsidian markdown.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s -i urls.txt -o ./clippings
  %(prog)s --urls https://en.wikipedia.org/wiki/Ecotone -o ./clippings
  %(prog)s -i pocket.md -o ./clippings/pocket --annotate-source --delay 2
  cat urls.txt | %(prog)s -o ./clippings --stdin
""",
    )
    # Input sources (mutually supportive, not exclusive)
    inp = p.add_argument_group("input")
    inp.add_argument("-i", "--input", metavar="FILE",
                     help="Text/markdown file containing URLs (one per line)")
    inp.add_argument("--urls", nargs="+", metavar="URL",
                     help="One or more URLs to process")
    inp.add_argument("--stdin", action="store_true",
                     help="Read URLs from stdin (one per line)")

    # Output
    out = p.add_argument_group("output")
    out.add_argument("-o", "--output", metavar="DIR", required=True,
                     help="Directory to write markdown files to")

    # Behaviour
    beh = p.add_argument_group("behaviour")
    beh.add_argument("--dry-run", action="store_true",
                     help="Preview what would be created without writing files")
    beh.add_argument("--overwrite", action="store_true",
                     help="Re-download and overwrite existing files")
    beh.add_argument("--limit", type=int, default=0, metavar="N",
                     help="Stop after processing N URLs (0 = unlimited)")
    beh.add_argument("--delay", type=float, default=DEFAULT_DELAY, metavar="SEC",
                     help=f"Per-domain cooldown in seconds (default: {DEFAULT_DELAY})")
    beh.add_argument("--workers", type=int, default=DEFAULT_WORKERS, metavar="N",
                     help=f"Parallel download threads (default: {DEFAULT_WORKERS}, 1 = sequential)")
    beh.add_argument("--annotate-source", action="store_true",
                     help="Add [[wikilink]] / failure annotations to the input file")
    beh.add_argument("--json-log", metavar="FILE",
                     help="Write a JSON log of all results to FILE")
    beh.add_argument("--summary-table", metavar="FILE",
                     help="Write a markdown summary table of results to FILE")

    return p


def main(argv=None):
    parser = build_parser()
    args = parser.parse_args(argv)

    # Gather URLs from all sources
    urls: list[str] = []
    if args.input:
        urls.extend(parse_urls_from_file(args.input))
    if args.urls:
        urls.extend(args.urls)
    if args.stdin:
        for line in sys.stdin:
            line = line.strip()
            if line.startswith("http://") or line.startswith("https://"):
                urls.append(line)

    if not urls:
        parser.error("No URLs provided. Use -i, --urls, or --stdin.")

    # Deduplicate while preserving order
    seen = set()
    deduped = []
    for u in urls:
        if u not in seen:
            seen.add(u)
            deduped.append(u)
    urls = deduped

    outdir = os.path.abspath(args.output)
    workers = max(1, args.workers)
    print("              __,__")
    print('     .--.  .-"     "-.  .--.')
    print("    / .. \\/  .-. .-.  \\/ .. \\")
    print("   | |  '|  /   Y   \\  |'  | |")
    print("   | \\   \\  \\ 0 | 0 /  /   / |")
    print('    \\ \'- ,\\.-"`` ``"-./, -\' /')
    print("     `'-' /_   ^ ^   _\\ '-'`")
    print("          |  \\._   _./  |")
    print("          \\   \\ `~` /   /")
    print("           '._ '-=-' _.'")
    print("              '~---~'   \U0001F34C ScrApe!")
    print()
    print(f"Ape out!  \u2014 {TODAY}")
    print(f"Nest:    {outdir}")
    print(f"Bananas: {len(urls)}")
    print(f"Troop:   {workers} ape{'s' if workers != 1 else ''}")
    if args.limit:
        print(f"Limit:   {args.limit}")
    print()

    os.makedirs(outdir, exist_ok=True)

    # Separate skippable URLs upfront
    to_process = []
    results = []
    counts = {"processed": 0, "ok": 0, "fail": 0, "skip": 0}

    for url in urls:
        if args.limit and len(to_process) >= args.limit:
            break
        if re.search(SKIP_EXTENSIONS, urlparse(url).path, re.I):
            results.append({"url": url, "success": False, "filename": "",
                            "error": "Non-article resource", "template": "skip"})
            counts["skip"] += 1
            print(f"  ⊘ Skip: {url}")
        else:
            to_process.append(url)

    def _do(url):
        return process_url(url, outdir, session=None,
                           dry_run=args.dry_run, overwrite=args.overwrite,
                           delay=args.delay)

    if workers == 1:
        # Sequential mode (legacy behaviour)
        session = requests.Session()
        session.headers.update(BROWSER_HEADERS)
        for url in to_process:
            r = process_url(url, outdir, session,
                            dry_run=args.dry_run, overwrite=args.overwrite,
                            delay=args.delay)
            results.append(r)
            counts["processed"] += 1
            counts["ok" if r["success"] else "fail"] += 1
    else:
        # Parallel mode
        futures = {}
        with ThreadPoolExecutor(max_workers=workers) as pool:
            for url in to_process:
                futures[pool.submit(_do, url)] = url
            for future in as_completed(futures):
                r = future.result()
                results.append(r)
                counts["processed"] += 1
                counts["ok" if r["success"] else "fail"] += 1

    # Summary
    print()
    print(f"── Ape Report ──────────────────")
    print(f"  Grabbed  : {counts['processed']}")
    print(f"  Peeled   : {counts['ok']}  🍌")
    print(f"  Dropped  : {counts['fail']}  💀")
    print(f"  Ignored  : {counts['skip']}  🙈")

    # Annotate source file
    if args.annotate_source and args.input and not args.dry_run:
        print(f"\nScribbling notes on {args.input} ...")
        annotate_source_file(args.input, results)
        print("Ooh ooh! Done.")

    # JSON log
    if args.json_log:
        with open(args.json_log, "w", encoding="utf-8") as f:
            json.dump(results, f, indent=2, ensure_ascii=False)
        print(f"Log written to {args.json_log}")

    # Summary table
    if args.summary_table:
        generate_summary_table(results, args.summary_table)
        print(f"Summary table written to {args.summary_table}")

    # Print failures
    failures = [r for r in results if not r["success"] and r["template"] != "skip"]
    if failures:
        print(f"\n── Dropped bananas ({len(failures)}) ─────────")
        for r in failures:
            print(f"  {r['url']}")
            print(f"    💀 {r['error']}")

    return 0 if counts["fail"] == 0 else 1


if __name__ == "__main__":
    sys.exit(main())

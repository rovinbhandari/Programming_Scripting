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

    # No grabbing at all: groom and sniff clippings that are already in the nest
    python ScrApe.py -o E:\\vault\\Clippings
    python ScrApe.py -o E:\\vault\\Clippings --dry-run --no-sniff
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

# ── Console encoding ───────────────────────────────────────────────────────
# Windows consoles default to cp1252, which chokes on the ape's emoji.
for _stream in (sys.stdout, sys.stderr):
    try:
        _stream.reconfigure(encoding="utf-8", errors="replace")
    except (AttributeError, ValueError, OSError):
        pass

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

# Image-related constants
IMAGE_LINK_RE = re.compile(r'!\[([^\]]*)\]\(([^)]+)\)')
IMAGE_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.svg', '.webp', '.bmp', '.ico'}
CONTENT_TYPE_MAP = {
    "image/jpeg": ".jpg", "image/png": ".png", "image/gif": ".gif",
    "image/webp": ".webp", "image/svg+xml": ".svg", "image/bmp": ".bmp",
}

# Magic bytes for image format validation (banana sniff)
IMAGE_MAGIC = {
    ".jpg":  [b"\xff\xd8\xff"],
    ".jpeg": [b"\xff\xd8\xff"],
    ".png":  [b"\x89PNG"],
    ".gif":  [b"GIF87a", b"GIF89a"],
    ".webp": [b"RIFF"],          # full check: bytes 8-12 == b"WEBP"
    ".bmp":  [b"BM"],
}

# Suspicious patterns in markdown files (banana sniff)
SNIFF_HTML_PATTERNS = [
    (re.compile(r"<script[\s>]", re.I), "embedded <script> tag"),
    (re.compile(r"<iframe[\s>]", re.I), "embedded <iframe> tag"),
    (re.compile(r"javascript\s*:", re.I), "javascript: URI"),
    (re.compile(r"\bon\w+\s*=\s*[\"']", re.I), "inline event handler (onclick, onerror…)"),
    (re.compile(r"\beval\s*\(", re.I), "eval() call"),
    (re.compile(r"data:text/html", re.I), "data:text/html URI"),
    (re.compile(r"data:application/", re.I), "data:application/ URI"),
]

# ── Link & image reference checks (banana sniff) ───────────────────────────
# Every markdown link/image target: "](url" — images are the subset preceded by "!"
MD_TARGET_RE = re.compile(r"\]\(\s*<?([^)<>\s]+)")
MD_IMAGE_TARGET_RE = re.compile(r"!\[[^\]]*\]\(\s*<?([^)<>\s]+)")
# Fenced code blocks hold examples, not references Obsidian will ever follow
CODE_FENCE_RE = re.compile(r"^(?P<f>```+|~~~+)[^\n]*\n.*?^(?P=f)[^\n]*$", re.M | re.S)
# Bare (autolinked) URLs, i.e. not already inside a markdown target or an attribute
BARE_URL_RE = re.compile(r"""(?<!["'(\[<])\b((?:https?|ftp|ftps)://[^\s<>)\]"']+)""", re.I)
HTML_SRC_RE = re.compile(r"""<[^>]*\bsrc\s*=\s*["']([^"']+)["']""", re.I)
HTML_HREF_RE = re.compile(r"""<[^>]*\bhref\s*=\s*["']([^"']+)["']""", re.I)

# Schemes that carry content without encryption
INSECURE_SCHEMES = {"http", "ftp"}
# Schemes that are fine to see in a clipping and need no host inspection
BENIGN_SCHEMES = {"mailto", "tel", "obsidian", "file"}

URL_SHORTENERS = {
    "bit.ly", "t.co", "tinyurl.com", "goo.gl", "ow.ly", "buff.ly", "is.gd",
    "cutt.ly", "rebrand.ly", "shorturl.at", "rb.gy", "t.ly", "lnkd.in",
    "dlvr.it", "trib.al", "amzn.to", "youtu.be", "fb.me", "wp.me", "s.id",
    "tiny.cc", "v.gd", "shorte.st", "adf.ly", "bl.ink", "clck.ru", "qr.ae",
    "ift.tt", "flip.it", "mol.im", "nyti.ms", "on.ft.com", "econ.st",
}

TRACKING_PARAM_RE = re.compile(
    r"^(utm_[a-z_]+|fbclid|gclid|dclid|msclkid|mc_cid|mc_eid|igshid|yclid|"
    r"twclid|ttclid|_hsenc|_hsmi|vero_id|oly_enc_id|ref_src|ref_url|spm|"
    r"scid|cmpid|campaign_id|s_cid|at_medium|at_campaign)$", re.I)

REDIRECT_PARAM_RE = re.compile(
    r"^(url|u|q|src|redirect|redirect_uri|redir|dest|destination|target|next|"
    r"out|link|goto|continue)$", re.I)

IPV4_HOST_RE = re.compile(r"^\d{1,3}(?:\.\d{1,3}){3}$")
STANDARD_PORTS = {80, 443, 21}

# ── Markdown tidy-up (banana groom) ────────────────────────────────────────
FRONTMATTER_RE = re.compile(r"\A---\n(.*?)\n---\n", re.S)
FM_SOURCE_RE = re.compile(r"""^source:\s*["']?(\S+?)["']?\s*$""", re.M)

# Wikipedia serves Parsoid HTML, whose citation markers survive the HTML→markdown
# step as raw <sup> blobs. They carry the #cite_note anchor of the reference.
SUP_BLOCK_RE = re.compile(r"<sup\b[^>]*>.*?</sup>", re.S | re.I)
CITE_NOTE_HREF_RE = re.compile(r"""href\s*=\s*["'][^"']*?(#cite_note-[^"']+)["']""", re.I)
# A reference-list entry always backlinks to its marker, whatever the language
CITE_REF_LINK_RE = re.compile(r"\]\([^)]*#cite_ref-")
CITE_FOOTNOTE_DEF_RE = re.compile(r"^\[\^c\]:", re.M)
MD_HEADING_RE = re.compile(r"^\s{0,3}#{1,6}\s")
MD_HEADING_PARTS_RE = re.compile(r"^\s{0,3}(#{1,6})\s+(.*?)\s*$")
# Wikipedia's shortened-footnote style splits the apparatus in two: numbered
# entries carrying the #cite_ref- backlinks, then the works those point at via
# #CITEREF anchors. Only the first tier is detectable by backlink, so the second
# is matched by heading — but solely when a #CITEREF link proves it is a second
# tier, which leaves a standalone bibliography or further reading list alone.
SHORTREF_LINK_RE = re.compile(r"\]\([^)]*#CITEREF")
BIBLIOGRAPHY_HEADINGS = frozenset({
    "bibliography", "sources", "works cited", "cited works", "references",
    "litteratur", "kilder", "referanser",
})
# Wikipedia's per-section [edit source] links, wrapped in escaped brackets.
# The section= lookahead keeps red links (action=edit&redlink=1) out of it —
# those are inline content links to articles that do not exist yet. Targets may
# carry escaped parens, as in Doughnut_\(economic_model\), so a plain [^)] scan
# would stop short of the query string.
_MD_TARGET = r"(?:\\.|[^)\\])*"
WIKI_EDIT_LINK_RE = re.compile(
    r"(?:\\\[\s*)?\[[^\]]*\]\("
    rf"(?={_MD_TARGET}\baction=edit\b)(?={_MD_TARGET}[&?]section=\d)"
    rf"{_MD_TARGET}\)(?:\s*\\\])?")
# 1x1 beacon Wikipedia leaves in the markup; it phones home whenever a note renders
WIKI_TRACKING_IMG_RE = re.compile(r"!\[[^\]]*\]\([^)\s]*Special:CentralAutoLogin[^)]*\)")
PROTOCOL_RELATIVE_RE = re.compile(r"\]\(\s*(//[^)\s]+)")
ROOT_RELATIVE_RE = re.compile(r"\]\(\s*(/[^/)\s][^)\s]*)")

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
#  Content quality check
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def _content_is_thin(markdown: str) -> bool:
    """Check if clipped markdown body (minus frontmatter) is suspiciously thin."""
    body = re.sub(r'^---\n.*?\n---\n', '', markdown, count=1, flags=re.DOTALL)
    lines = [l for l in body.strip().splitlines() if l.strip()]
    return len(lines) < 5 or len(body.strip()) < 200


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Image downloading
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def _guess_image_ext(url: str, content_type: str = "") -> str:
    """Guess file extension from URL path or Content-Type header."""
    path = urlparse(url).path
    _, ext = os.path.splitext(path.split("?")[0])
    if ext.lower() in IMAGE_EXTENSIONS:
        return ext.lower()
    for ct, e in CONTENT_TYPE_MAP.items():
        if ct in content_type.lower():
            return e
    return ".jpg"


def _download_single_image(img_url: str, dest_path: str,
                           session: requests.Session, delay: float) -> bool:
    """Download one image file. Returns True on success."""
    try:
        _domain_wait(img_url, delay)
        resp = session.get(img_url, timeout=REQUEST_TIMEOUT, stream=True)
        resp.raise_for_status()
        ct = resp.headers.get("Content-Type", "")
        if "image" not in ct and "octet-stream" not in ct:
            return False
        os.makedirs(os.path.dirname(dest_path), exist_ok=True)
        with open(dest_path, "wb") as f:
            for chunk in resp.iter_content(8192):
                f.write(chunk)
        return True
    except Exception:
        return False


def download_and_relink_images(
    markdown: str, source_url: str, slug: str,
    assets_dir: str, md_path: str,
    session: requests.Session, delay: float,
) -> tuple[str, int, int]:
    """
    Download images referenced in markdown to assets_dir/slug/,
    rewrite image links to relative Obsidian paths.

    Returns (updated_markdown, downloaded_count, failed_count).
    """
    img_dir = os.path.join(assets_dir, slug)
    md_dir = os.path.dirname(md_path)
    rel_prefix = os.path.relpath(img_dir, md_dir).replace("\\", "/")

    downloaded = 0
    failed = 0
    seen_names: set[str] = set()

    def _replace_image(match):
        nonlocal downloaded, failed
        alt = match.group(1)
        img_url = match.group(2).strip()

        # Skip data URIs, empty srcs, and already-local paths
        if not img_url or img_url.startswith("data:") or not img_url.startswith("http"):
            return match.group(0)

        # Determine deduplicated local filename
        url_path = urlparse(img_url).path
        base_name = os.path.basename(url_path.split("?")[0]) or "image"
        base_name = sanitize_filename(base_name)
        if not os.path.splitext(base_name)[1]:
            base_name += ".jpg"
        if base_name in seen_names:
            stem, ext = os.path.splitext(base_name)
            i = 2
            while f"{stem}_{i}{ext}" in seen_names:
                i += 1
            base_name = f"{stem}_{i}{ext}"
        seen_names.add(base_name)

        dest = os.path.join(img_dir, base_name)
        if os.path.exists(dest):
            downloaded += 1
            return f"![{alt}]({rel_prefix}/{base_name})"

        if _download_single_image(img_url, dest, session, delay):
            downloaded += 1
            _safe_print(f"      📸 {base_name}")
            return f"![{alt}]({rel_prefix}/{base_name})"
        else:
            failed += 1
            _safe_print(f"      ❌ {img_url}")
            return match.group(0)  # keep original URL on failure

    updated = IMAGE_LINK_RE.sub(_replace_image, markdown)
    return updated, downloaded, failed


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
#  Wayback Machine fallback
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

WAYBACK_API = "https://archive.org/wayback/available?url={}"


def wayback_lookup(url: str) -> str | None:
    """Ask the Wayback Machine if it has a snapshot. Returns the archived URL or None."""
    try:
        r = requests.get(WAYBACK_API.format(url), timeout=10)
        r.raise_for_status()
        snap = r.json().get("archived_snapshots", {}).get("closest", {})
        if snap.get("available"):
            return snap["url"]
    except Exception:
        pass
    return None


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
                delay: float = DEFAULT_DELAY,
                wayback: bool = False,
                download_images: bool = False,
                assets_dir: str | None = None) -> dict:
    """One ape, one banana. Grab, peel, save. Returns the loot report."""
    result = {"url": url, "success": False, "filename": "", "error": "",
              "template": "", "images_downloaded": 0, "images_failed": 0}

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

    # Wayback fallback: if the direct grab failed, ask the archive
    if err and wayback:
        _safe_print(f"    🐒 {err} — asking the old monkeys...")
        wb_url = wayback_lookup(url)
        if wb_url:
            _safe_print(f"    🐒 Fossilized banana found!")
            resp, err2 = fetch_page(wb_url, session)
            if err2:
                _safe_print(f"    💀 Fossilized banana was rotten: {err2}")
            else:
                err = None  # clear the original error
                result["wayback"] = wb_url
        else:
            _safe_print(f"    💀 Even the elder apes have forgotten this one")

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

    # Content quality check: if thin and wayback enabled, try Wayback version
    if wayback and _content_is_thin(content) and "wayback" not in result:
        _safe_print(f"    🐒 Content looks thin — asking the old monkeys...")
        wb_url = wayback_lookup(url)
        if wb_url:
            _safe_print(f"    🐒 Fossilized banana found! Comparing...")
            wb_resp, wb_err = fetch_page(wb_url, session)
            if not wb_err:
                wb_soup = BeautifulSoup(wb_resp.text, "html.parser")
                try:
                    if template == "wikipedia":
                        _, wb_content = clip_wikipedia(url, wb_soup)
                    elif template == "goodreads":
                        _, wb_content = clip_goodreads(url, wb_soup)
                    else:
                        _, wb_content = clip_default(url, wb_soup)
                    if len(wb_content) > len(content):
                        content = wb_content
                        result["wayback"] = wb_url
                        _safe_print(f"    🐒 Wayback version is meatier — using it!")
                except Exception:
                    pass

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

    # Download images if requested (skip for goodreads — just a cover URL)
    if download_images and template != "goodreads":
        slug = sanitize_filename(filename).lower().replace(" ", "-")[:60]
        adir = assets_dir or os.path.join(os.path.dirname(outdir), "Assets", "Pocket")
        content, dl, fl = download_and_relink_images(
            content, url, slug, adir, filepath, session, delay)
        result["images_downloaded"] = dl
        result["images_failed"] = fl
        if dl > 0 or fl > 0:
            _safe_print(f"    📸 Images: {dl} downloaded"
                        + (f", {fl} failed" if fl else ""))

    os.makedirs(outdir, exist_ok=True)
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)

    result["success"] = True
    _safe_print(f"    🍌 {filename}.md ({template})")
    return result


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  Banana Sniff — post-download content security check
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def _iter_references(text: str):
    """Yield (is_image, url) for every link/image reference in a markdown file."""
    text = CODE_FENCE_RE.sub(lambda m: "\n" * m.group(0).count("\n"), text)
    image_starts = {m.start(1) for m in MD_IMAGE_TARGET_RE.finditer(text)}
    for m in MD_TARGET_RE.finditer(text):
        yield m.start(1) in image_starts, m.group(1).strip()
    for m in HTML_SRC_RE.finditer(text):
        yield True, m.group(1).strip()
    for m in HTML_HREF_RE.finditer(text):
        yield False, m.group(1).strip()
    for m in BARE_URL_RE.finditer(text):
        yield False, m.group(1).strip()


def _sniff_url(url: str, is_image: bool) -> list[str]:
    """Smell-check a single link/image target. Returns finding descriptions."""
    kind = "image" if is_image else "link"
    findings: list[str] = []

    if not url or url.startswith("#"):
        return findings

    # Protocol-relative: inherits whatever scheme the renderer happens to use
    if url.startswith("//"):
        findings.append(f"protocol-relative {kind} URL (scheme-inheriting)")
        to_parse = "https:" + url
    else:
        to_parse = url

    try:
        parsed = urlparse(to_parse)
    except ValueError as exc:
        findings.append(f"unparseable {kind} URL ({exc})")
        return findings

    if not url.startswith("//"):
        scheme = parsed.scheme.lower()
        if not scheme:
            return findings          # local relative path — exactly what we want
        if scheme in BENIGN_SCHEMES:
            return findings
        if scheme == "data":
            return findings          # already covered by SNIFF_HTML_PATTERNS
        if scheme in INSECURE_SCHEMES:
            findings.append(f"insecure {scheme}:// {kind} (unencrypted)")
        elif scheme not in ("https", "ftps"):
            findings.append(f"unexpected '{scheme}:' scheme in {kind}")

    if is_image and parsed.scheme.lower() in ("http", "https"):
        findings.append("remote image not downloaded locally")

    host = (parsed.hostname or "").lower()
    if host:
        if IPV4_HOST_RE.match(host) or ":" in host:
            findings.append(f"raw IP address host in {kind}")
        if host.startswith("xn--") or ".xn--" in host:
            findings.append(f"punycode/IDN host in {kind}")
        if host in URL_SHORTENERS:
            findings.append(f"URL shortener host '{host}' (opaque redirect)")

    if parsed.username or parsed.password:
        findings.append(f"credentials embedded in {kind} URL")

    try:
        port = parsed.port
    except ValueError:
        port = None
        findings.append(f"malformed port in {kind} URL")
    if port is not None and port not in STANDARD_PORTS:
        findings.append(f"non-standard port :{port} in {kind}")

    if parsed.query:
        for pair in parsed.query.split("&"):
            name = pair.split("=", 1)[0]
            if TRACKING_PARAM_RE.match(name):
                findings.append(f"tracking parameter '{name}' in {kind}")
            elif REDIRECT_PARAM_RE.match(name) and "%3a%2f%2f" in pair.lower():
                findings.append(f"redirect wrapper parameter '{name}' in {kind}")
            elif REDIRECT_PARAM_RE.match(name) and "://" in pair:
                findings.append(f"redirect wrapper parameter '{name}' in {kind}")

    return findings


def _sniff_references(text: str) -> list[str]:
    """Aggregate link/image findings across a whole file, with one example each."""
    counts: dict[str, int] = {}
    examples: dict[str, str] = {}

    for is_image, url in _iter_references(text):
        for finding in _sniff_url(url, is_image):
            counts[finding] = counts.get(finding, 0) + 1
            examples.setdefault(finding, url)

    lines = []
    for finding, count in counts.items():
        example = examples[finding]
        if len(example) > 70:
            example = example[:67] + "…"
        suffix = f" (×{count})" if count > 1 else ""
        lines.append(f"{finding}{suffix} — e.g. {example}")
    return lines


def _sniff_markdown(path: str) -> list[str]:
    """Smell-check a markdown file for suspicious content."""
    findings = []
    try:
        text = open(path, "r", encoding="utf-8", errors="replace").read()
    except Exception as e:
        return [f"Could not read file: {e}"]

    for pattern, description in SNIFF_HTML_PATTERNS:
        matches = pattern.findall(text)
        if matches:
            findings.append(f"{description} (×{len(matches)})")

    findings.extend(_sniff_references(text))

    return findings


def _sniff_image(path: str) -> list[str]:
    """Check that an image file's magic bytes match its extension."""
    findings = []
    ext = os.path.splitext(path)[1].lower()
    expected = IMAGE_MAGIC.get(ext)

    if expected is None:
        # Unknown image extension — can't validate, but note it
        if ext not in (".ico", ".svg"):
            findings.append(f"unknown image extension '{ext}'")
        return findings

    try:
        with open(path, "rb") as f:
            header = f.read(16)
    except Exception as e:
        return [f"Could not read file: {e}"]

    if len(header) == 0:
        return ["empty file (0 bytes)"]

    # SVG files are text-based — check first bytes for XML/SVG marker
    if ext == ".svg":
        text_start = header.decode("utf-8", errors="replace").lstrip()
        if not (text_start.startswith("<?xml") or text_start.startswith("<svg")):
            findings.append("file does not start with <?xml or <svg")
        return findings

    # Binary image: check magic bytes
    if not any(header.startswith(magic) for magic in expected):
        # Detect if it's actually HTML masquerading as an image
        try:
            snippet = header[:64].decode("utf-8", errors="replace").lower().strip()
        except Exception:
            snippet = ""
        if snippet.startswith("<!doctype") or snippet.startswith("<html"):
            findings.append("HTML content disguised as image file")
        else:
            actual_hex = header[:8].hex(" ")
            findings.append(f"magic bytes mismatch (got {actual_hex})")

    # Extra check for .webp: bytes 8-12 should be "WEBP"
    if ext == ".webp" and header[:4] == b"RIFF" and header[8:12] != b"WEBP":
        findings.append(f"RIFF container but not WEBP (got {header[8:12]!r})")

    return findings


def banana_sniff(clippings_dir: str, assets_dir: str | None = None) -> int:
    """
    🐒 The Banana Sniff — inspect downloaded clippings and images for
    suspicious content, insecure links and un-localised images.
    Returns the number of total findings.
    """
    print()
    print("── 🐒 Banana Sniff ─────────────────")
    print(f"  Clippings: {clippings_dir}")
    if assets_dir:
        print(f"  Assets:    {assets_dir}")
    print()

    total_findings = 0
    md_checked = 0
    img_checked = 0

    # ── Sniff markdown files ──
    if os.path.isdir(clippings_dir):
        for root, _dirs, files in os.walk(clippings_dir):
            for fname in sorted(files):
                if not fname.endswith(".md"):
                    continue
                fpath = os.path.join(root, fname)
                findings = _sniff_markdown(fpath)
                md_checked += 1
                if findings:
                    total_findings += len(findings)
                    rel = os.path.relpath(fpath, clippings_dir)
                    print(f"  🍌🐛 {rel}")
                    for f in findings:
                        print(f"         └─ {f}")

    # ── Sniff image files ──
    img_dir = assets_dir or clippings_dir
    if os.path.isdir(img_dir):
        for root, _dirs, files in os.walk(img_dir):
            for fname in sorted(files):
                ext = os.path.splitext(fname)[1].lower()
                if ext not in IMAGE_EXTENSIONS:
                    continue
                fpath = os.path.join(root, fname)
                findings = _sniff_image(fpath)
                img_checked += 1
                if findings:
                    total_findings += len(findings)
                    rel = os.path.relpath(fpath, img_dir)
                    print(f"  🍌🐛 {rel}")
                    for f in findings:
                        print(f"         └─ {f}")

    # ── Summary ──
    print()
    if total_findings == 0:
        print(f"  ✅ All bananas clean! ({md_checked} markdown, {img_checked} images)")
    else:
        print(f"  ⚠️  {total_findings} suspicious finding{'s' if total_findings != 1 else ''}"
              f" ({md_checked} markdown, {img_checked} images checked)")
    print()

    return total_findings


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#  🦧 Banana Groom — tidy up already-clipped markdown
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def _groom_source_url(text: str) -> str:
    """The `source:` of a clipping, used as the base for relative targets."""
    fm = FRONTMATTER_RE.match(text)
    if not fm:
        return ""
    m = FM_SOURCE_RE.search(fm.group(1))
    return m.group(1) if m else ""


def _strip_inline(text: str, pattern: re.Pattern) -> tuple[str, int]:
    """Remove every match of `pattern`, dropping any line the match leaves empty."""
    kept: list[str] = []
    count = 0
    for line in text.split("\n"):
        stripped, n = pattern.subn("", line)
        if n:
            count += n
            if not stripped.strip():
                continue  # the match was all the line held
        kept.append(stripped)
    return "\n".join(kept), count


def _groom_edit_links(text: str) -> tuple[str, int]:
    """Drop Wikipedia's per-section [edit source] links, which are not vault content."""
    if "action=edit" not in text or "section=" not in text:
        return text, 0
    return _strip_inline(text, WIKI_EDIT_LINK_RE)


def _groom_tracking_pixels(text: str) -> tuple[str, int]:
    """Drop Wikipedia's 1x1 CentralAutoLogin beacon, which phones home on render."""
    if "CentralAutoLogin" not in text:
        return text, 0
    return _strip_inline(text, WIKI_TRACKING_IMG_RE)


def _groom_citation_markers(text: str, source: str, refs_heading: str) -> tuple[str, int]:
    """
    Replace raw <sup> citation blobs with a single shared [^c] footnote pointing
    at the live article's reference section. Wikipedia's own #cite_note anchors
    are mostly positional, so a link to one silently rots into a different
    source as the article gains references; [^c] cannot.
    """
    if not source or "<sup" not in text.lower():
        return text, 0

    count = 0

    def _convert(match: re.Match) -> str:
        nonlocal count
        blob = match.group(0)
        if not CITE_NOTE_HREF_RE.search(blob):
            return blob
        count += 1
        return "[^c]"

    text = SUP_BLOCK_RE.sub(_convert, text)
    if not count:
        return text, 0

    if not CITE_FOOTNOTE_DEF_RE.search(text):
        target = source.split("#", 1)[0]
        if refs_heading:
            target += "#" + refs_heading.replace(" ", "_")
        text = text.rstrip("\n") + f"\n\n[^c]: [References]({target})\n"

    return text, count


def _groom_reference_list(text: str) -> tuple[str, int, str]:
    """
    Drop the imported reference list, which [^c] now stands in for. Entries are
    recognised by their #cite_ref- backlinks rather than by heading text, so this
    works whatever language the article is in. A heading is only removed when
    references were all it contained; its text is returned so the footnote can
    link straight to that section of the original.
    """
    if not CITE_REF_LINK_RE.search(text):
        return text, 0, ""

    lines = text.split("\n")
    bounds = [-1] + [i for i, line in enumerate(lines) if MD_HEADING_RE.match(line)]
    bounds.append(len(lines))

    keep = [True] * len(lines)
    removed = 0
    heading = ""

    for start, end in zip(bounds, bounds[1:]):
        refs = [i for i in range(start + 1, end) if CITE_REF_LINK_RE.search(lines[i])]
        if not refs:
            continue
        removed += len(refs)
        # A bundled reference carries its sources on indented lines beneath it,
        # which are orphaned if only the entry itself goes
        drop: set[int] = set()
        for i in refs:
            drop.add(i)
            j = i + 1
            while j < end and lines[j][:1].isspace() and lines[j].strip():
                drop.add(j)
                j += 1
        others = [i for i in range(start + 1, end)
                  if lines[i].strip() and i not in drop]
        if others:
            for i in drop:
                keep[i] = False
        else:
            # Nothing but references under this heading — take the section with it
            if start >= 0 and not heading:
                heading = MD_HEADING_RE.sub("", lines[start]).strip()
            for i in range(max(start, 0), end):
                keep[i] = False

    return "\n".join(line for i, line in enumerate(lines) if keep[i]), removed, heading


def _groom_bibliography(text: str) -> tuple[str, int]:
    """
    Remove the second tier of a shortened-footnote apparatus: the works the short
    citations pointed at. Carries no backlinks of its own, so unlike the first
    tier it has to be matched by heading, and a section is only taken when the
    note is already known to use shortened footnotes.
    """
    lines = text.split("\n")
    heads = []
    for i, line in enumerate(lines):
        m = MD_HEADING_PARTS_RE.match(line)
        if m:
            heads.append((i, len(m.group(1)), m.group(2).strip().lower()))

    keep = [True] * len(lines)
    removed = 0
    for pos, (start, level, title) in enumerate(heads):
        if title not in BIBLIOGRAPHY_HEADINGS:
            continue
        end = len(lines)
        for j, deeper, _ in heads[pos + 1:]:
            if deeper <= level:
                end = j                      # a sibling or shallower heading ends it
                break
        removed += sum(1 for k in range(start, end)
                       if lines[k].lstrip().startswith(("- ", "* ")))
        for k in range(start, end):
            keep[k] = False

    if removed == 0:
        return text, 0
    return "\n".join(line for i, line in enumerate(lines) if keep[i]), removed


def _groom_urls(text: str, source: str) -> tuple[str, int]:
    """Absolutise protocol-relative and root-relative link and image targets."""
    total = 0
    text, n = PROTOCOL_RELATIVE_RE.subn(lambda m: "](https:" + m.group(1), text)
    total += n

    if source:
        parts = urlparse(source)
        if parts.scheme and parts.netloc:
            origin = f"{parts.scheme}://{parts.netloc}"
            text, n = ROOT_RELATIVE_RE.subn(lambda m: "](" + origin + m.group(1), text)
            total += n

    return text, total


def _groom_markdown(path: str) -> tuple[list[str], str | None]:
    """Groom one file. Returns (change descriptions, new text or None if unchanged)."""
    with open(path, "r", encoding="utf-8", newline="") as f:
        raw = f.read()

    crlf = "\r\n" in raw
    text = original = raw.replace("\r\n", "\n")
    source = _groom_source_url(text)
    if not source:
        return [], None          # not a clipping — hands off notes we did not fetch

    changes: list[str] = []

    def _note(count: int, singular: str, plural: str):
        if count:
            changes.append(f"{count} {singular if count == 1 else plural}")

    text, n = _groom_edit_links(text)
    _note(n, "edit link removed", "edit links removed")

    text, n = _groom_tracking_pixels(text)
    _note(n, "tracking pixel removed", "tracking pixels removed")

    # Only trade the reference list away when there are markers to stand in for it
    has_markers = bool(source) and any(
        CITE_NOTE_HREF_RE.search(m.group(0)) for m in SUP_BLOCK_RE.finditer(text))

    refs_heading = ""
    if has_markers:
        # The #CITEREF links live in the first tier, so look before removing it
        shortrefs = bool(SHORTREF_LINK_RE.search(text))
        text, n, refs_heading = _groom_reference_list(text)
        _note(n, "imported reference dropped", "imported references dropped")

        if shortrefs:
            text, n = _groom_bibliography(text)
            _note(n, "cited work dropped", "cited works dropped")

    text, n = _groom_citation_markers(text, source, refs_heading)
    _note(n, "citation marker footnoted", "citation markers footnoted")

    text, n = _groom_urls(text, source)
    _note(n, "relative target absolutised", "relative targets absolutised")

    if text == original:
        return [], None
    return changes, text.replace("\n", "\r\n") if crlf else text


def banana_groom(clippings_dir: str, dry_run: bool = False) -> int:
    """
    🦧 The Banana Groom — pick the nits out of clipped markdown: swap Wikipedia
    citation markers for a [^c] footnote pointing at the original's reference
    section, drop the imported reference list, and absolutise relative targets.
    Grooming is idempotent, so it is safe to run over the same nest twice.
    Returns the number of files changed.
    """
    print()
    print("── 🦧 Banana Groom ─────────────────")
    print(f"  Clippings: {clippings_dir}")
    if dry_run:
        print("  Dry run:   no files will be written")
    print()

    changed = 0
    checked = 0

    if os.path.isdir(clippings_dir):
        for root, _dirs, files in os.walk(clippings_dir):
            for fname in sorted(files):
                if not fname.endswith(".md"):
                    continue
                fpath = os.path.join(root, fname)
                changes, new_text = _groom_markdown(fpath)
                checked += 1
                if new_text is None:
                    continue
                changed += 1
                if not dry_run:
                    with open(fpath, "w", encoding="utf-8", newline="") as f:
                        f.write(new_text)
                rel = os.path.relpath(fpath, clippings_dir)
                print(f"  🦧🧹 {rel}")
                for change in changes:
                    print(f"         └─ {change}")

    print()
    if changed == 0:
        print(f"  ✅ Every banana already glossy! ({checked} markdown)")
    else:
        verb = "would be groomed" if dry_run else "groomed"
        print(f"  🦧 {changed} file{'s' if changed != 1 else ''} {verb} ({checked} markdown checked)")
    print()

    return changed


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
    beh.add_argument("--wayback", action="store_true",
                     help="Try Wayback Machine if direct grab fails or content is thin")
    beh.add_argument("--download-images", action="store_true",
                     help="Download referenced images to local assets folder and rewrite links")
    beh.add_argument("--assets-dir", metavar="DIR",
                     help="Directory for downloaded images (default: <output>/../Assets/Pocket)")
    beh.add_argument("--sniff", action="store_true", default=True, dest="sniff",
                     help="Run the 🐒 Banana Sniff content, link and image check (default: on)")
    beh.add_argument("--no-sniff", action="store_false", dest="sniff",
                     help="Skip the 🐒 Banana Sniff post-download content check")
    beh.add_argument("--groom", action="store_true", default=True, dest="groom",
                     help="Run the 🦧 Banana Groom markdown tidy-up (default: on)")
    beh.add_argument("--no-groom", action="store_false", dest="groom",
                     help="Skip the 🦧 Banana Groom markdown tidy-up")

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
        if args.groom or args.sniff:
            # Standalone mode — no scraping, just work over existing files
            outdir = os.path.abspath(args.output)
            adir = args.assets_dir or os.path.join(os.path.dirname(outdir), "Assets", "Pocket")
            if args.groom:
                banana_groom(outdir, dry_run=args.dry_run)
            findings = banana_sniff(outdir, adir) if args.sniff else 0
            return 0 if findings == 0 else 1
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
    print("              '~---~'   🍌 ScrApe!")
    print()
    print(f"Ape out!  — {TODAY}")
    print(f"Nest:    {outdir}")
    print(f"Bananas: {len(urls)}")
    print(f"Troop:   {workers} ape{'s' if workers != 1 else ''}")
    if args.limit:
        print(f"Limit:   {args.limit}")
    if args.wayback:
        print(f"Wayback: 🐒 Elder apes on standby")
    if args.download_images:
        adir = args.assets_dir or os.path.join(os.path.dirname(outdir), "Assets", "Pocket")
        print(f"Images:  📸 Downloading to {adir}")
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

    img_kw = {"download_images": args.download_images,
              "assets_dir": args.assets_dir}

    def _do(url):
        return process_url(url, outdir, session=None,
                           dry_run=args.dry_run, overwrite=args.overwrite,
                           delay=args.delay, wayback=args.wayback, **img_kw)

    if workers == 1:
        # Sequential mode (legacy behaviour)
        session = requests.Session()
        session.headers.update(BROWSER_HEADERS)
        for url in to_process:
            r = process_url(url, outdir, session,
                            dry_run=args.dry_run, overwrite=args.overwrite,
                            delay=args.delay, wayback=args.wayback, **img_kw)
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
    img_dl = sum(r.get("images_downloaded", 0) for r in results)
    img_fl = sum(r.get("images_failed", 0) for r in results)
    print()
    print(f"── Ape Report ──────────────────")
    print(f"  Grabbed  : {counts['processed']}")
    print(f"  Peeled   : {counts['ok']}  🍌")
    print(f"  Dropped  : {counts['fail']}  💀")
    print(f"  Ignored  : {counts['skip']}  🙈")
    if img_dl or img_fl:
        print(f"  Images   : {img_dl} saved 📸" + (f", {img_fl} failed" if img_fl else ""))

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

    # Banana Groom — tidy the freshly peeled markdown
    if args.groom and not args.dry_run:
        banana_groom(outdir)

    # Banana Sniff — post-scrape content check
    if args.sniff and not args.dry_run:
        adir = args.assets_dir or os.path.join(os.path.dirname(outdir), "Assets", "Pocket")
        banana_sniff(outdir, adir)

    return 0 if counts["fail"] == 0 else 1


if __name__ == "__main__":
    sys.exit(main())

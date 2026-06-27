# Decision research: Keyword / keyphrase extraction

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex extract **keywords / keyphrases** from file content (for keyword search and tagging) — classical algorithms, embedding-based, or an LLM?

## Context & constraints
- **On-device default**, cheap enough to run over **many files** during idle troughs.
- **Multilingual** is desirable; should **degrade gracefully** on low-end CPUs.
- Minimal deps; **permissive licenses only** — flag copyleft.
- **Pluggable:** hide behind a `KeywordExtractor` trait; allow tiering (cheap → richer) per file.

## Options
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **yake-rust** | YAKE statistical extractor | Unsupervised, **language-agnostic**, good single-doc quality; 36+ langs; MIT | Per-doc only; statistical (no semantics) |
| **rake** (`rake`) | RAKE stopword phrase extraction | Tiny (~200 LoC), fast; MIT/Apache | English-centric stopwords; simpler quality |
| ~~keyword_extraction~~ | TF-IDF/RAKE/TextRank/YAKE/co-occurrence in one | Many algorithms; parallel | ⚠️ **LGPL-3.0-or-later** — copyleft; static-link ambiguity conflicts with pandex licensing → **avoid** |
| **KeyBERT-style** (via fastembed) | Embed doc + n-grams, cosine top-k | **Semantic** quality; **reuses the embedding dep** ([`embeddings-and-inference.md`](embeddings-and-inference.md)); no new crate | Needs an embedding model loaded; ~50–200 ms/doc |
| LLM prompt (Ollama / candle / llama-cpp-2) | "Extract keyphrases" prompt | Best quality, **abstractive** (phrases not literally in text) | ~0.5–5 s/doc on CPU; heavy; idle-only |

**Quality vs cost (rough):**
| Method | Quality | Latency | Extra RAM |
|---|---|---|---|
| RAKE | ⭐⭐ | <1 ms | ~0 |
| YAKE | ⭐⭐⭐ | ~1–5 ms | ~0 |
| KeyBERT-style (fastembed) | ⭐⭐⭐⭐ | 50–200 ms | ~100–400 MB (model) |
| Local LLM prompt | ⭐⭐⭐⭐⭐ | 0.5–5 s | ~1–4 GB (model) |

## Recommendation
Use a **classical default** — **yake-rust** (MIT; better single-doc quality, multilingual) as primary, with **rake** as a lightweight alternative — behind a `KeywordExtractor` trait, because it's near-zero cost and fully offline, ideal for bulk enrichment. **Avoid `keyword_extraction`** (LGPL-3.0-or-later; static-linking copyleft ambiguity is incompatible with pandex's PolyForm licensing). Offer an optional **semantic upgrade** that implements **KeyBERT-style** extraction on top of the existing **fastembed** embeddings (no new dependency) for higher-value files, and optionally an **LLM-prompt** extractor for the richest results during deep idle. Proposal, not a lock.

## Open questions
- Default algorithm (**YAKE** vs **RAKE**) and per-language stopword handling.
- **Tiering policy:** when to escalate a file classical → embedding → LLM extraction.
- Language **detection** (which stopword set / model per file)?
- Where to **store** keywords — an FTS5 column vs a separate tags table (ties to [`index-store.md`](index-store.md)).

## References
- https://github.com/quesurifn/yake-rust · https://crates.io/crates/yake-rust
- https://github.com/yaa110/rake-rs · https://crates.io/crates/rake
- https://github.com/tugascript/keyword-extraction-rs — `keyword_extraction` (**LGPL-3.0**, flagged).
- https://github.com/MaartenGr/KeyBERT — KeyBERT (Python; the pattern reproduced via fastembed).

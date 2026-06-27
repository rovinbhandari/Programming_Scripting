# Prior art: similar projects & pandex's niche

> A living survey of tools adjacent to pandex, and the gap it fills. Revisit this as we make the **topology** and **index-store** decisions in [`../architecture.md`](../architecture.md), and whenever we meet a new tool — does it close our niche?

**Status:** Living reference
**Owner:** Rovin  ·  **Date:** 2026-06-27 (star counts verified this date via shields.io badges; they drift — treat as approximate)

## Why this note
We keep one honest list of what already exists so we can (a) borrow good ideas, (b) reuse mature building blocks instead of rebuilding, and (c) stay clear-eyed about what actually makes pandex worth building. If a new tool ever ticks every box under [Our niche](#our-niche), that is a signal to rethink scope.

## The landscape

### Cross-device / distributed file indexers
| Project | Lang | ★ | What it is | vs pandex |
|---|---|---|---|---|
| [Spacedrive](https://github.com/spacedriveapp/spacedrive) | Rust | ~38k | Cross-device "VDFS": P2P sync, cloud connectors (OpenDAL), BLAKE3, LanceDB+FastEmbed semantic search | Closest analog, but a full GUI **file manager** + sync + AI runtime; pandex is a headless, in-place **indexer** |
| [Perkeep](https://github.com/perkeep/perkeep) (Camlistore) | Go | ~7k | Content-addressable personal blob store with sync | **Imports** files into its own store; no embeddings/RAG |

### Local content search (keyword, no embeddings)
| Project | Lang | ★ | Notes |
|---|---|---|---|
| [Recoll](https://www.recoll.org/) | C++ | — | Mature, 200+ formats (Xapian backend); single machine |
| [sist2](https://github.com/sist2app/sist2) | C | ~1.3k | Fast incremental scan, OCR, thumbnails; single machine |
| [ripgrep-all](https://github.com/phiresky/ripgrep-all) | Rust | ~9.7k | Regex *inside* PDFs/docx/archives; no persistent index |
| [fselect](https://github.com/jhspetersson/fselect) | Rust | ~4.4k | SQL-like queries over file **metadata**; no content/embeddings |
| [Everything](https://www.voidtools.com/) | C++ (closed) | — | Instant **filename** search; Windows/NTFS only |

### Semantic search & RAG over files (mostly Python, single-machine)
| Project | Lang | ★ | Notes |
|---|---|---|---|
| [Khoj](https://github.com/khoj-ai/khoj) | Python | ~35k | Docs Q&A, many clients, local or cloud LLMs |
| [PrivateGPT](https://github.com/zylon-ai/private-gpt) | Python | ~57k | OpenAI-compatible RAG API layer over your docs |
| [Quivr](https://github.com/quivrhq/quivr) | Python | ~39k | Opinionated RAG framework |
| [Onyx](https://github.com/onyx-dot-app/onyx) (ex-Danswer) | Python | ~31k | 50+ **cloud-service** connectors, hybrid index |
| [Reor](https://github.com/reorproject/reor) | TS/Electron | ~8.6k | AI notes app; LanceDB; **Markdown only** |
| [txtai](https://github.com/neuml/txtai) | Python | ~13k | Embeddings-DB toolkit (build-on-it, not a file indexer) |

### Media-only analogues
| Project | Lang | Notes |
|---|---|---|
| [PhotoPrism](https://github.com/photoprism/photoprism) | Go | Self-hosted photos; CLIP semantic search, faces, EXIF/GPS |
| [Immich](https://github.com/immich-app/immich) | TS/Kotlin | Self-hosted photo/video; CLIP, metadata/face search |

*Also adjacent but off-axis:* DocFetcher (Java desktop search), Datasette (publishing structured data, not a file scanner), Rewind.ai (macOS screen-recording search, closed-source).

## Closest analog: Spacedrive
Spacedrive is the one project squarely in pandex's territory — Rust core, cross-device, content hashing, and LanceDB-backed semantic search. The divergence is **scope**: Spacedrive is a full application (Tauri desktop + mobile, file operations, P2P sync via Iroh/QUIC, an "AI agent" runtime, content-safety quarantine). pandex deliberately does *less*: it does not move, sync, or manage files — it indexes them in place and answers queries, as a headless daemon other tools can sit on top of. Notably, Spacedrive also ships under a **source-available** license (FSL-1.1) rather than OSI open source, similar to PolyForm (see [`licenses.md`](licenses.md)).

## Candidate building blocks (Rust)
- **[Tantivy](https://github.com/quickwit-oss/tantivy)** (~15k★) — Lucene-style full-text search; BM25, incremental indexing.
- **[LanceDB](https://github.com/lancedb/lancedb)** — embedded vector store, columnar, **auto-versioned**; used by *both* Spacedrive and Reor.
- **[Meilisearch](https://github.com/meilisearch/meilisearch)** / **[Quickwit](https://github.com/quickwit-oss/quickwit)** — server-grade hybrid/distributed search, if we ever outgrow an embedded store.

These feed the **Index store** open decision and are compared properly there when we reach it; listed here only as "prior art exists, don't rebuild it."

## Our niche
No surveyed tool combines **all** of the following. Re-check each box whenever we meet a new tool — if one ticks them all, that is a prompt to revisit scope.

- [ ] **Cross-device, in-place aggregation** — index many machines' files where they sit; no import, no forced sync. (Spacedrive syncs; Perkeep imports; everything else is single-machine.)
- [ ] **Idle/trough-aware enrichment** — heavy work (embeddings, keyword extraction) runs only when the device is idle. (No comparable tool schedules around device usage.)
- [ ] **Metadata-first, content-opt-in** — cheap metadata for *everything*; embeddings only where they earn their cost. (Most either index all content or only chosen doc types.)
- [ ] **Explicit on-device vs hosted model choice** — per use-case, privacy-first. (Most hardcode or imply one mode.)
- [ ] **Versioned data + schema from day zero** — safe migrations; swap vector backends without a full re-index.
- [ ] **Rust, headless, composable** — an indexer daemon other tools query, sitting between fselect/rga (stateless) and Spacedrive (full platform).

## Open questions
- Worth a deeper look at Spacedrive's script-based adapter protocol and OpenDAL for our connector interface?
- Does "no-sync, in-place" hold up for online stores, or do some sources force a local cache/staging copy?

## References
- Compiled 2026-06-27 from each project's GitHub repo / homepage (links above); star counts via shields.io badges, same date. Counts drift — re-verify before quoting.

# Decision research: Index store (metadata + full-text + vectors)

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
What embedded store(s) should hold pandex's file **metadata**, its **keyword / full-text** index, and (optionally) **vector embeddings** — one unified file, or best-of-breed components behind a trait?

## Context & constraints
- **Embedded / local-first:** no server to run on a laptop; ideally a single data file to back up or move.
- **Cross-platform single binary** (Windows/macOS/Linux), incl. low-end devices → small binary, modest RAM, no heavy build toolchain. Prefer **C-only** deps over C++/CMake.
- Metadata is **relational** (files × tags × paths × enrichments) → SQL fits naturally.
- **Phased:** M2 = metadata + filename/keyword search; M3 = document-content search + semantic (vector) search.
- **Versioned schema** with safe migrations — see [`schema-migrations.md`](schema-migrations.md).
- **Permissive deps only** (no GPL/AGPL).
- **Pluggable:** hide the store behind `Searcher` / `VectorStore` traits so pieces can be swapped without touching metadata logic.

## Options

### SQLite access (driver)
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **rusqlite** (`bundled-full`) | Sync C-binding; de-facto standard | Mature & widely used; MIT; `bundled-full` ships FTS5; ~700 KB; pairs cleanly with `sqlite-vec`; full PRAGMA/extension access | Sync only (wrap in `spawn_blocking`); no compile-time SQL checks |
| **sqlx** | Async; compile-time-checked SQL | Async-native; `query!` verifies SQL; built-in `migrate!`; MIT/Apache | Needs a DB at build time (or offline `.json`); heavier dep tree |
| sea-orm | Async ORM over sqlx/rusqlite | Entities + migrations; MIT/Apache | Proc-macro/compile overhead; hides SQLite-specific features; v2 in RC |
| diesel | Sync ORM, strong compile checks | Very mature; MIT/Apache | Sync-only (async is 3rd-party); awkward dynamic queries |
| libsql | Turso SQLite fork | WAL2 + sync features; MIT | Overkill for local-only; heavy dep tree; pre-1.0 |
| _redb / fjall_ | Pure-Rust KV engines | No C toolchain; ACID; MIT/Apache | **No SQL/FTS/vectors** — re-implement joins by hand |
| ~~sled~~ | Pure-Rust KV | — | 1.0 rewrite stuck in alpha since ~2022 → avoid |

### Full-text search
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **SQLite FTS5** | Built-in C virtual table | Zero extra dep; **same file, same transaction**; BM25; auto-synced via triggers | Tokenizer/snippet less rich than Tantivy |
| **tantivy** | Pure-Rust Lucene-like | Rich tokenizers/snippets/BM25; widely used (Quickwit); MIT; great for long-form content | Separate store; app-managed consistency; sync API |

### Vector / ANN
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **sqlite-vec** | C SQLite extension | **Vectors in the same SQLite file**, transactional; MIT/Apache; simple SQL | Brute-force O(n) beyond ~500k; ANN (IVF) still alpha; needs C compiler |
| hnsw_rs | Pure-Rust HNSW | Portable, multithreaded; MIT/Apache | Separate file; single (academic) maintainer |
| usearch | C++ HNSW | Very fast SIMD; single-file index; Apache | C++ toolchain; separate file |
| arroy | LMDB-backed ANN (Meilisearch) | Memory-efficient, production-tested; MIT (LMDB = permissive OpenLDAP) | C dep; batch-build; Windows LMDB quirks |
| lancedb | Pure-Rust columnar vector DB | Vectors+metadata co-located; Apache | Multi-file; heavy Arrow deps; slow compile; **no FTS** |
| duckdb + VSS | C++ OLAP + vector ext | Powerful analytics; MIT | CMake/C++; ~40–50 MB binary; OLAP, not OLTP |
| ~~qdrant~~ | Vector **server** | — | Not embeddable (separate process) → dismiss |

### Candidate architectures
| | **A — one SQLite file** | **B — best-of-breed** | **C — LanceDB** |
|---|---|---|---|
| Layout | SQLite + FTS5 + sqlite-vec | SQLite + Tantivy + hnsw_rs/usearch | Lance (vectors+meta) + Tantivy FTS |
| Single file | ✅ | ❌ (3 stores) | ❌ |
| FTS quality | Adequate | Excellent | External |
| Vectors at scale | OK (<~500k) | Excellent | Excellent |
| Consistency | ✅ atomic | ⚠️ app-managed | ⚠️ app-managed |
| Build toolchain | Low (C) | Low (pure Rust) | Medium (heavy deps) |
| Fits pandex values | ✅ strongly | partial | weak |

## Recommendation
Start with **Architecture A**: **rusqlite** (`bundled-full`) + **sqlite-vec** in one SQLite file, **FTS5** for keyword/metadata search, migrations via **refinery** (see [`schema-migrations.md`](schema-migrations.md)). One file, ACID, C-only toolchain, fewest moving parts — squarely matches the minimal/embedded values. Define `Searcher` and `VectorStore` traits from day one so **Tantivy** (content FTS) and a dedicated ANN (**hnsw_rs**/**usearch**) can slot in at M3 when the corpus crosses ~100k docs / ~500k vectors — without rewriting metadata logic. Proposal, not a lock.

## Open questions
- Sync (**rusqlite** + `spawn_blocking`) vs async-native (**sqlx**) metadata layer — depends on [`async-runtime.md`](async-runtime.md).
- Expected vectors-per-device (drives sqlite-vec brute-force vs a dedicated ANN, and *when*).
- When does content-search quality (M3) justify Tantivy's separate store?
- Single-file simplicity now vs accepting 3 managed stores later.

## References
- https://crates.io/crates/rusqlite · https://github.com/rusqlite/rusqlite
- https://crates.io/crates/sqlx · https://github.com/launchbadge/sqlx
- https://www.sqlite.org/fts5.html — FTS5.
- https://github.com/asg017/sqlite-vec · https://crates.io/crates/sqlite-vec
- https://github.com/quickwit-oss/tantivy
- https://github.com/lancedb/lancedb · https://github.com/cberner/redb · https://github.com/fjall-rs/fjall
- https://github.com/jean-pierreBoth/hnswlib-rs (hnsw_rs) · https://github.com/unum-cloud/USearch · https://github.com/meilisearch/arroy
- Overlaps the building-blocks in [`prior-art.md`](prior-art.md) (Tantivy, LanceDB).

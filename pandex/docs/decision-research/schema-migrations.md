# Decision research: Schema & data migrations

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex **version and migrate** its on-disk schema/data safely across releases and across a fleet of devices?

## Context & constraints
- Versioned data/schema is a **core project value**; the schema version must live **in the DB**.
- Embedded SQLite on user devices → migrations are **forward-only** in practice; a crash mid-migration must be recoverable.
- Minimal deps; **sync** path likely (if [`index-store.md`](index-store.md) picks rusqlite), so an async-only migrator is a poor fit.
- Reproducible: migrations should be **embedded in the binary** (no loose files to ship).
- Migrations may trigger **surgical re-scans / re-enrichment** rather than destructive rewrites.

## Options
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **refinery** | Framework-agnostic SQL migration runner | Works **directly with rusqlite** (sync); `embed_migrations!` compiles SQL in; **checksums**; plain history table; MIT; active | Versions are `i32` by default (feature for `i64`); no auto-rollback (down is manual) |
| **sqlx::migrate!** | Built into sqlx | Async-native; compile-time embed; checksums; **no extra dep** if sqlx is the driver | Requires sqlx + an async context |
| sea-orm-migration | sea-orm DSL migrations | Type-safe DDL; up/down; MIT/Apache | Tied to sea-orm; verbose; v2 RC |
| diesel migrations | diesel ecosystem | Strong types; up/down; compile-time embed | Sync; tied to diesel ORM |
| `PRAGMA user_version` | Built-in SQLite integer | Zero dep; works with **any** driver | No history/checksums; hand-rolled runner; doesn't scale past a few migrations |

## Recommendation
If the driver is **rusqlite**, use **refinery** (`rusqlite` feature): SQL files compiled into the binary, checksum-verified, with an inspectable history table and **no async requirement**. Use SQLite's **`PRAGMA user_version`** as the cheap startup **handshake** — read it to decide whether the migrator needs to run at all. If pandex instead adopts **sqlx**, prefer its built-in **`sqlx::migrate!`** and drop refinery (one fewer dep). Keep migrations **forward-only** on user devices and treat data-format bumps with the same release discipline as code. Proposal, not a lock — it follows the driver decision in [`index-store.md`](index-store.md).

## Open questions
- Driver choice (rusqlite vs sqlx) decides refinery vs `sqlx::migrate!` — resolve in [`index-store.md`](index-store.md).
- Policy for destructive migrations / backfills: re-enrich vs surgical re-scan, scheduled in idle troughs.
- Do user devices ever need reversible (down) migrations, or is forward-only + backup enough?
- If we later add Tantivy/ANN (Architecture B), how do we coordinate **multi-store** version bumps atomically?

## References
- https://crates.io/crates/refinery · https://github.com/rust-db/refinery
- https://docs.rs/sqlx/latest/sqlx/macro.migrate.html — `sqlx::migrate!`.
- https://www.sqlite.org/pragma.html#pragma_user_version — `PRAGMA user_version`.
- https://www.sea-ql.org/SeaORM/docs/migration/setting-up-migration/ — sea-orm-migration.

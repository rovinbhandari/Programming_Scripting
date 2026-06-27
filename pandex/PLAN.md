# pandex — PLAN

The living plan of work and decisions in flight. See [`AGENTS.md`](AGENTS.md) for the rules and [`docs/architecture.md`](docs/architecture.md) for the overview and decision log.

## Mission
Build a unified, queryable index of data files scattered across many devices and stores — minimal, modular, and correct at every step.

## Current phase: Design (pre-implementation)
We are deliberately designing before building: requirements, validation sets, tooling, language, and LLM choices. No implementation code yet.

## Working agreement
- Ask, don't assume; one decision at a time.
- Record decisions in `docs/architecture.md` (edit/subtract, don't just append).
- Keep `docs/` tree-structured: abstract at the root (for autonomous, high-capability implementation), granular at the leaves (for cheap, feature-by-feature implementation).
- Verify build/test/rubber-duck before committing; one commit per holistic change.
- Never commit real data.

## Design backlog (open decisions)
Worked through roughly in this order; each settles into an entry in the architecture decision log (`docs/architecture.md`), which owns the rationale.
- [ ] **Topology** — single-machine tool vs central index aggregating many devices vs hub + agents.
- [ ] **Language** — confirm Rust (leaning) and the minimum toolchain.
- [ ] **Index store** — embedded (SQLite/FTS, sqlite-vec, Tantivy, LanceDB) vs server; how vectors live alongside metadata. → [`index-store.md`](docs/decision-research/index-store.md)
- [ ] **Index scope** — metadata-only first, then opt-in content keywords/embeddings; which file types. → [`file-types-and-metadata.md`](docs/decision-research/file-types-and-metadata.md)
- [ ] **LLM hosting** — local/on-device vs hosted API, for keyword extraction, embeddings, search, and RAG. → [`embeddings-and-inference.md`](docs/decision-research/embeddings-and-inference.md), [`keyword-extraction.md`](docs/decision-research/keyword-extraction.md)
- [ ] **Connectors** — the pluggable "source" interface for disks, VMs, and online stores. → [`storage-connectors.md`](docs/decision-research/storage-connectors.md), [`fs-scan-and-watch.md`](docs/decision-research/fs-scan-and-watch.md), [`file-access-and-hydration.md`](docs/decision-research/file-access-and-hydration.md)
- [ ] **Scheduling** — detecting device-usage troughs; async pipeline for embeddings/keywords. → [`async-runtime.md`](docs/decision-research/async-runtime.md)
- [ ] **Versioning** — data + schema versioning and migration strategy. → [`schema-migrations.md`](docs/decision-research/schema-migrations.md)
- [ ] **Observability** — telemetry + benchmark harness to find and document slow parts. → [`observability.md`](docs/decision-research/observability.md), [`benchmarking.md`](docs/decision-research/benchmarking.md)
- [ ] **Validation sets** — fixtures and golden queries we measure correctness and quality against.

## Milestones (tentative)
- **M0 — Scaffolding.** AGENTS, README, TODO, docs, PLAN. ← in progress
- **M1 — Architecture v1.** Topology, language, store, and indexing scope agreed and drawn.
- **M2 — Vertical slice.** Scan one local folder → metadata index → keyword search, end to end.
- **M3 — Content understanding.** Async keyword extraction + embeddings, opt-in.
- **M4 — Multi-source.** A second connector (e.g. another device or an online store).
- **M5 — RAG.** Ask questions, get answers grounded in your files.

## Immediate next steps
1. Agree the architecture-doc depth: strawman now vs fill collaboratively.
2. Tackle **Topology** — the first open decision — and draw it.
3. Lock the language and minimal toolchain.

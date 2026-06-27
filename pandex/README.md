# pandex 🔥🐼🔥

> **pan-index** — one index to find every file, wherever it lives.

<img src="pandex_mascot.png" width="500" alt="pandex mascot">

pandex builds a single, queryable index of the data files scattered across your world: laptops, desktops, VMs, external drives, and online storage.
The premise is simple: you have files *everywhere*, and no single place to ask "where is that thing, and what's in it?"
pandex aims to be that place.
Our guide and mascot is an **omniscient Red Panda** 🔥🐼🔥 — *red* for Rust, *panda* for **pand**ex — who has (eventually) read every file so you don't have to.

## The problem
Data sprawls.
A photo lives on one backup drive, a code repo on a VM, a dataset in cloud storage, a half-finished draft on an old laptop.
Operating systems each ship their own search, but none see *across* devices, and their content understanding is limited — keyword matching at best, rarely search by *meaning*.
pandex treats every location as a source to scan, then unifies what it finds into one index you can search by name, by metadata, by keyword, and — eventually — by meaning.

## What it will do (goals)
- **Scan many sources** — local disks, removable drives, VMs, and online stores, via pluggable connectors.
- **Index metadata first** — path, size, type, timestamps, hashes — cheaply and for everything.
- **Understand content (opt-in)** — extract keywords and embeddings so you can search by topic and meaning, not just filename.
- **Search well** — keyword and semantic search, with retrieval-augmented answers (RAG) over your own files.
- **Stay current cheaply** — surgical re-scans of only what changed, not full rebuilds.
- **Respect the machine** — run across operating systems and prefer idle, low-usage windows for heavy work.
- **Version everything** — data and schema are versioned so the index can evolve without breaking.

## Status
Very early.
We are **designing the architecture** before writing implementation code — discussing requirements, validation sets, tooling, language, and LLM choices.
Nothing is implemented yet, and key choices are deliberately still open.
Start here: [`docs/architecture.md`](docs/architecture.md) for the overview and open decisions, [`PLAN.md`](PLAN.md) for the plan of work, and [`TODO.md`](TODO.md) for near-term tasks.

## Principles
- **Minimal and correct.** Keep the codebase small, modular, and functionally correct at every step.
- **Pluggable over monolithic.** Sources, extractors, models, and stores swap behind clean interfaces.
- **Performance is a feature.** Measure with telemetry and benchmarks, then fix the slow parts.
- **Ask, don't assume.** Where reasonable choices diverge, we surface options and decide together.
- **Leaning Rust.** The implementation language is inclined toward Rust, but not yet locked.
- **Privacy by design.** We index personal files, so *where* models run — on-device vs hosted API — is an explicit open decision, not an afterthought.

## Layout
- `README.md` — you are here.
- `AGENTS.md` — rules of engagement for AI agents working in this folder.
- `docs/` — architecture overview and deeper concept notes.
- `PLAN.md` — the living plan of work and decisions in flight.
- `TODO.md` — near-term and backburnered tasks.

## A note on lineage
pandex is the real-world destination of the Rust learning track in [`../Rust`](../Rust) — the "file indexer" those exercises quietly build toward.
🔥🐼🔥 *Trivia:* the red panda wore the name *panda* first — *Ailurus fulgens*, "shining cat," was catalogued in 1825, some 44 years before the giant panda borrowed the label. The original holder of the index entry, you might say.

## License
**Source-available, not open source.** pandex is licensed under the [PolyForm Noncommercial License 1.0.0](LICENSE.md) — use, modify, and share it for any **noncommercial** purpose; **commercial use requires permission**. © 2026 Rovin Bhandari. Rationale: [`docs/decision-research/licenses.md`](docs/decision-research/licenses.md).

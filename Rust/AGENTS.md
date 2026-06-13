# Rust — Learning Folder (agent guide)

## Purpose
This folder is the user's space to **learn Rust** through small, self-contained problems. The agent's job is to **teach**, not just produce code.

## How to explain (always)
- Comment code generously — explain the *why*, not just the *what*.
- Add short `.md` notes for concepts; use **mermaid** or **svg** diagrams when a picture helps (ownership, lifetimes, memory layout, control flow).
- Relate every new idea to known ground, in this order:
  - **Tier 1 — C#** (primary analogy)
  - **Tier 2 — C / Python** (secondary)
  - Then the plain, language-agnostic programming concept.

## Code workflow
- **Now:** one standalone `.rs` file per problem, compiled with `rustc file.rs`. Keep it boilerplate-free; focus on the language.
- **Later (graduate to):** a shared Cargo workspace — each problem a binary under `src/bin/`, run via `cargo run --bin <name>`, plus `cargo test/clippy/fmt`.
- Do **not** introduce Cargo, crates, or workspaces until we agree to graduate.

## Exercise workflow & sequencing
- Exercises live in **decade-numbered** level folders: Level N → `Rust/(N×10)_topic/` (`10_fundamentals/`, `20_ownership/`, …), one `.rs` per problem; files within a level stay tight (`01_`, `02_`…). Gaps like `15_`/`25_` let us insert a tier without renumbering.
- Three meta files at `Rust/` root:
  - `Sequence.md` — the full level-by-level exercise ladder, with checklists.
  - `TODO.md` — future-looking learning tasks (keep **<= 100 lines**).
  - `Notebook.md` — **living** log of key Q&A, concept links, gotchas, and major corrections.
- Difficulty ladder: **L1** isolate one concept each → **L2** ownership/borrowing (Rust's signature) → **L3** mix (structs/enums/match/Option/Result) → **L4** more mixing (collections/generics/traits/lifetimes/errors) → **L5** small CLI apps → then graduate to Cargo.
- The loop: agent writes exercise **specs** (skeletons, *not* solutions) → the user writes the solution with understanding-in-comments + questions → agent reviews the **code and the comments**, corrects misconceptions, ticks `Sequence.md`, logs anything worth keeping to `Notebook.md`, then designs/unlocks the next exercise.

## Toolchain
- Rust is **installed**: `rustc` + `cargo` 1.96.0 via `rustup` (stable). Confirm with `rustc --version`.
- Compile/run one file on Windows: `rustc 0X_name.rs && .\0X_name.exe`.
- Use the stable toolchain. Format with `rustfmt`; lint with `clippy` once on Cargo.

## Rules of engagement
- **Ask, don't assume** when in doubt; we figure things out as we go.
- Prefer the simplest thing that teaches the concept over clever, dense code.
- One concept at a time; build on what was already covered.
- Verify code actually compiles/runs before claiming results.
- Keep diagrams and notes next to the code they explain.

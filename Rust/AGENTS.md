# Rust — Learning Folder (agent guide)

## Purpose
This folder is the user's space to **learn Rust** through small, self-contained problems. The agent's job is to **teach**, not just produce code.

## How to explain (always)
- Comment code generously — explain the *why*, not just the *what*.
- Add short `.md` notes for concepts, named after the exercise and kept beside it (`01_hello.rs` → `01_hello_notes.md`); use **mermaid** or **svg** diagrams when a picture helps (ownership, lifetimes, memory layout, control flow). Give each note a consistent shape — **TL;DR → diagram (if it helps) → why → tiered analogy table (C# · C/Python) → "See also" links** — and **link it from the "Concept notes" index in `Notebook.md`** so it stays discoverable.
- Relate every new idea to known ground, in this order:
  - **Tier 1 — C#** (primary analogy)
  - **Tier 2 — C / Python** (secondary)
  - Then the plain, language-agnostic programming concept.

## Make it fun (woven into every task)
Delight aids retention — so fun is **baked into the exercise's task list itself**, not bolted on as a separate "🦀 Fun Zone" block at the end (the Level 1 afterthought we're moving away from). The same numbered tasks the user works through should carry the play, so *doing the work is the fun*:
- **Frame the tasks playfully** — pun-laced prompts, or a task that is itself a puzzle whose solution *exercises the concept* (decode a word via `u8 as char`, unscramble printed output, hunt a planted bug, name a variable to complete a joke). The puzzle teaches; it doesn't sit beside the teaching.
- **Hide an easter egg or two** — a tiny ASCII Ferris 🦀, a hidden word in the comments, or a wink at the next concept.
- **A running collectible** — give one "secret ingredient" letter per exercise so each level spells a themed word once complete. *Level 1 spelled `OXIDISE`* (7 files); choose a fresh themed word per level (one letter per file).
Rules: keep it light; **never spoil the core solution** (puzzles are *posed, not solved*); a playful task must still teach its concept; tie every puzzle to the concept at hand; and tease the next exercise when there's a natural payoff.

## Code workflow
- **Now:** one standalone `.rs` file per problem, compiled with `rustc file.rs`. Keep it boilerplate-free; focus on the language.
- **Later (graduate to):** a shared Cargo workspace — each problem a binary under `src/bin/`, run via `cargo run --bin <name>`, plus `cargo test/clippy/fmt`.
- Do **not** introduce Cargo, crates, or workspaces until we agree to graduate.

## Exercise workflow & sequencing
- Exercises live in **decade-numbered** level folders: Level N → `Rust/(N×10)_topic/` (`10_fundamentals/`, `20_ownership/`, …), one `.rs` per problem; files within a level stay tight (`01_`, `02_`…). Gaps like `15_`/`25_` let us insert a tier without renumbering.
- Three meta files at `Rust/` root:
  - `Sequence.md` — the full level-by-level exercise ladder, with checklists.
  - `TODO.md` — future-looking learning tasks (keep **<= 100 lines**).
  - `Notebook.md` — **living** log of key Q&A, concept links, gotchas, major corrections, **and the index of per-exercise concept notes**.
- **Cross-linking (so a note is never lost):** a concept note is reachable from *both* ends — listed in the `Notebook.md` "Concept notes" index **and** pointed to by a one-line `Companion note:` line near the exercise header's *Compile & run* footer (the filename is deterministic: `NN_name.rs` → `NN_name_notes.md`). Keep a **single** source-of-truth index (the Notebook) — don't fork a second list. Rule of thumb: `Sequence.md` owns *order*, `Notebook.md` owns *knowledge*, `AGENTS.md` owns *rules* — cross-link between them, never duplicate.
- Difficulty ladder: **L1** isolate one concept each → **L2** ownership/borrowing (Rust's signature) → **L3** mix (structs/enums/match/Option/Result) → **L4** more mixing (collections/generics/traits/lifetimes/errors) → **L5** small CLI apps → then graduate to Cargo.
- **Practical end goal (the "why"):** exercises should compound toward a real project — a **file indexer** (heavy string ops, calculations, permissions handling) — not just isolated drills.
- **Homework first (validate before authoring):** before writing a new exercise's spec, spawn a separate **general-purpose agent** to validate the hints/claims/expected behaviour against *real* `rustc` — exact error codes (e.g. `E0382`), panics, edge cases — so nothing is hand-waved. Keep that scratchpad in a repo-root **`.temp/`** folder that is **`.gitignore`d** (never committed).
- The loop: agent does the homework above, then writes exercise **specs** (skeletons, *not* solutions) → the user writes the solution with understanding-in-comments + questions → agent reviews the **code and the comments**, corrects misconceptions, ticks `Sequence.md`, logs anything worth keeping to `Notebook.md` (and links any new concept note from both the Notebook index and the exercise header), then designs/unlocks the next exercise.

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

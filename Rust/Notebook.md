# Rust Notebook

A **living** log for the learning journey — the place we don't want to lose things.
Maintained across sessions (this convention is declared in `AGENTS.md`, so any agent picks it up automatically).

**What goes here**
- **Q&A** — good questions you asked and the answers we landed on.
- **Concept links** — curated, trustworthy references per topic.
- **Gotchas** — surprising Rust behaviours and the mistakes that bite beginners.
- **Corrections** — major misconceptions caught during review (so we can revisit them).

**How we keep it** — I add an entry during review whenever something is worth remembering.
Keep entries short and link out to the relevant exercise file or doc. Newest first within each section. Date format: `YYYY-MM-DD`.

---

## Q&A
<!-- Template:
### Q: <the question, in your words>   ·   (ex: 10_fundamentals/04_functions.rs · 2026-06-13)
A: <the answer we agreed on, 1–4 lines>. See: <link or file>.
-->

## Concept links
Canonical, stable references (good default sources):
- The Rust Book — https://doc.rust-lang.org/book/
- Rust by Example — https://doc.rust-lang.org/rust-by-example/
- Standard library docs — https://doc.rust-lang.org/std/
- The Reference (deep / spec) — https://doc.rust-lang.org/reference/
- Rustlings (extra practice) — https://github.com/rust-lang/rustlings

Per-topic (added as we go):
- Level 1 fundamentals → Book ch. 3 "Common Programming Concepts":
  https://doc.rust-lang.org/book/ch03-00-common-programming-concepts.html

## Gotchas
<!-- Template:
- **<short title>** — <what surprises people> (ex: <file> · <date>).
-->
- **`rustc` drops the binary in your current folder** — on Windows you get `name.exe` (and a `name.pdb`); run it with `.\name.exe`. Both are git-ignored, so they won't be committed. (setup · 2026-06-13)

## Corrections
<!-- Template:
### <date> — <topic>   (ex: <file>)
- **You had:** <the misconception, from your comments>.
- **Actually:** <the correct mental model>.
- **Takeaway:** <the one-line rule to remember>.
-->
_(empty — major corrections from reviews will be logged here)_

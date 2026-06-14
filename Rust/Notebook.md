# Rust Notebook

A **living** log for the learning journey — the place we don't want to lose things. Maintained across sessions (this convention is declared in `AGENTS.md`, so any agent picks it up automatically).

**What goes here**
- **Q&A** — good questions you asked and the answers we landed on.
- **Concept links** — curated, trustworthy references per topic.
- **Gotchas** — surprising Rust behaviours and the mistakes that bite beginners.
- **Corrections** — major misconceptions caught during review (so we can revisit them).

**How we keep it** — I add an entry during review whenever something is worth remembering. Keep entries short and link out to the relevant exercise file or doc. Newest first within each section. Date format: `YYYY-MM-DD`.

---

## Q&A
<!-- Template:
### Q: <the question, in your words>   ·   (ex: 10_fundamentals/04_functions.rs · 2026-06-13)
A: <the answer we agreed on, 1–4 lines>. See: <link or file>.
-->

### Q: Why is `println!` a macro, not a function?   ·   (ex: 10_fundamentals/01_hello.rs · 2026-06-14)
A: Macros expand at **compile time** on the token/syntax tree (not C-preprocessor text substitution), so `println!` can take a variable number of args *and* check the format string against them while compiling — a plain fn can't (Rust has no variadics outside `extern "C"`). Wrong placeholders are a compile error, not a runtime crash. See: https://doc.rust-lang.org/book/ch19-06-macros.html · Deep-dive: [01_hello_notes.md](10_fundamentals/01_hello_notes.md)

### Q: Is `Display` (`{}`) auto-implemented for my own types?   ·   (ex: 10_fundamentals/01_hello.rs · 2026-06-14)
A: No — `Display` is never derived; you hand-write `impl std::fmt::Display`. Only `Debug` (`{:?}`) can be auto-derived with `#[derive(Debug)]`. That's exactly why `{point}` won't compile but `{point:?}` will. See: https://doc.rust-lang.org/std/fmt/

### Q: Can `println!` take an arbitrary number of comma-separated values?   ·   (ex: 10_fundamentals/01_hello.rs · 2026-06-14)
A: Yes for a **fixed** list — `println!("{} {} {}", a, b, c)` — each arg matched to a placeholder; too few or too many is a compile error. But the count is fixed by the format string at compile time (no runtime-variable arity); to print a dynamic collection, print the collection itself with `{:?}` or loop. See: https://doc.rust-lang.org/std/macro.println.html

## Concept links
Canonical, stable references (good default sources):
- The Rust Book — https://doc.rust-lang.org/book/
- Rust by Example — https://doc.rust-lang.org/rust-by-example/
- Standard library docs — https://doc.rust-lang.org/std/
- The Reference (deep / spec) — https://doc.rust-lang.org/reference/
- Rustlings (extra practice) — https://github.com/rust-lang/rustlings

Per-topic (added as we go):
- Level 1 fundamentals → Book ch. 3 "Common Programming Concepts": https://doc.rust-lang.org/book/ch03-00-common-programming-concepts.html

## Concept notes
In-repo deep-dives that pair with an exercise (newest first). Each lives next to its `.rs` and is listed here so it stays findable:
- [`println!` is a macro — compile-time formatting](10_fundamentals/01_hello_notes.md) — why the `!`, how the format string is checked while compiling, and a C#/C/Python "when is it checked?" table. (ex: 10_fundamentals/01_hello.rs · 2026-06-14)

## Gotchas
<!-- Template:
- **<short title>** — <what surprises people> (ex: <file> · <date>).
-->
- **Derived `Debug` doesn't count as "using" a field** — printing a struct with `{:?}` still fires the `dead_code` warning ("fields are never read"); the compiler intentionally ignores derived impls during dead-code analysis (otherwise the lint could never flag a genuinely unused field). Silence it by reading a field in real code, or with `#[allow(dead_code)]`. (ex: 10_fundamentals/01_hello.rs · 2026-06-14)

## Corrections
<!-- Template:
### <date> — <topic>   (ex: <file>)
- **You had:** <the misconception, from your comments>.
- **Actually:** <the correct mental model>.
- **Takeaway:** <the one-line rule to remember>.
-->
_(empty — major corrections from reviews will be logged here)_

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

### Q: Why is it called "borrowing" and not "sharing", if the original binding stays valid?   ·   (playground/borrowing.rs · 2026-06-15)
A: Because **ownership never transfers** — the owner keeps the title and gets the value back; a *loan*, not joint ownership. "Share" only fits the immutable `&T` case (many read-only borrows at once; the owner can still read). The other kind, `&mut T`, is **exclusive**: exactly one, and the owner is **locked out** while it's live — there the car analogy fits perfectly. What truly invalidates the original ("I don't have it anymore") is a **move**, not a borrow. The whole model is one rule — *shared XOR mutable*, and no borrow outlives its owner. Runnable demo + Fun Zone challenges: [playground/borrowing.rs](playground/borrowing.rs) · deep-dive [notes](playground/borrowing_notes.md).

### Q: On integer overflow, does a debug build differ from a release build?   ·   (ex: 10_fundamentals/03_scalar_types.rs · 2026-06-15)
A: Yes. For `+ - *`: if the compiler can const-fold the overflow it's a **compile error** (`arithmetic_overflow`, deny-by-default) — but that catch is *opportunistic* (even a `println!` of the value first can defeat it). Otherwise it's a **runtime** call: **debug panics** ("attempt to add with overflow"), **release (`-O`) wraps** (two's complement). `as` casts never panic — they truncate/saturate. For defined behaviour use `checked_/wrapping_/saturating_/overflowing_`. Deep-dive: [03_scalar_types_notes.md](10_fundamentals/03_scalar_types_notes.md)

### Q: Why is a Rust `char` 4 bytes, not 1?   ·   (ex: 10_fundamentals/03_scalar_types.rs · 2026-06-15)
A: A `char` is a **Unicode scalar value** (any code point `U+0000..=U+10FFFF` minus surrogates), which needs 21 bits → stored as 4 bytes. That's why `'🦀'` (U+1F980) fits in a single `char`. Note a `char` is one scalar value, *not* a user-perceived glyph — some emoji are several `char`s. (In a `String`/`&str`, text is UTF-8, so `'🦀'` takes 4 bytes there but ASCII takes 1.) See: https://doc.rust-lang.org/std/primitive.char.html

### Q: What's the difference between `const` and an immutable `let`?   ·   (ex: 10_fundamentals/02_variables.rs · 2026-06-15)
A: A `const` is a **compile-time** value: known while compiling, **inlined** at each use site (no fixed address unless you take `&`), always needs a type, and may live at module/global scope. An immutable `let` is a **runtime binding**: it occupies a place on the stack, can be initialised from runtime work (`let now = clock();`), and is local to its block. Both forbid reassignment — but `const` ≈ a named literal, `let` ≈ a value you promise not to reassign. Deep-dive: [02_variables_notes.md](10_fundamentals/02_variables_notes.md)

### Q: Why must a `const` have an explicit type when a `let` often doesn't?   ·   (ex: 10_fundamentals/02_variables.rs · 2026-06-15)
A: Rust runs type **inference only inside function bodies**. `const` (like `static`, `fn` signatures and struct fields) is an **item** — it can sit at module level and be referenced anywhere — so the compiler never infers it; you annotate it. A `let` lives in a fn body where local inference applies, so its type is usually optional. And a `const` is inlined rather than stored, so there's no single initializer slot to infer a type *from*. See: https://doc.rust-lang.org/book/ch03-01-variables-and-mutability.html#constants

### Q: Why is an immutable binding still called a "variable"?   ·   (ex: 10_fundamentals/02_variables.rs · 2026-06-15)
A: "Variable" just means a **named binding** (a name bound to a value) — inherited from maths/other languages; it says nothing about mutability. "Immutable by default" only means you can't **reassign** it without `mut`. Some Rustaceans say "binding" to dodge the confusion. See: https://doc.rust-lang.org/book/ch03-01-variables-and-mutability.html

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
- [Numeric casts & integer overflow — `as`, debug vs release](10_fundamentals/03_scalar_types_notes.md) — when `as` truncates/saturates, when overflow is a compile error vs a debug panic vs a release wrap, and the checked/wrapping/saturating/overflowing menu. (ex: 10_fundamentals/03_scalar_types.rs · 2026-06-15)
- [Naming values — `let`, `let mut`, shadowing, `const`](10_fundamentals/02_variables_notes.md) — binding-vs-place model (mut overwrites, shadowing rebinds & can retype), const vs immutable `let`, and why only items need explicit types. (ex: 10_fundamentals/02_variables.rs · 2026-06-15)
- [`println!` is a macro — compile-time formatting](10_fundamentals/01_hello_notes.md) — why the `!`, how the format string is checked while compiling, and a C#/C/Python "when is it checked?" table. (ex: 10_fundamentals/01_hello.rs · 2026-06-14)

## Gotchas
<!-- Template:
- **<short title>** — <what surprises people> (ex: <file> · <date>).
-->
- **`as` casts never panic — they silently truncate/saturate** — `300i32 as u8` → `44`, `3.9 as i32` → `3` (toward zero), `1e20 as i32` → `i32::MAX`, `NaN as i32` → `0`. Perfect when you mean "lossy, do it anyway"; for a *checked* conversion use `u8::try_from(x)`. (ex: 10_fundamentals/03_scalar_types.rs · 2026-06-15)
- **A variable can be named after a type** — `let i32: i32 = 84;` compiles because **types and values are separate namespaces**, so the binding `i32` doesn't clash with the type `i32`. Legal, but confusing — prefer real names. (ex: 10_fundamentals/03_scalar_types.rs · 2026-06-15)
- **Shadowing can mark the *first* binding "unused"** — `let x = 5;` then later a fresh `let x = 5;` (without reading the first) fires `unused variable: x` pointing at the **first** `let`, not the later one. Shadowing is a brand-new binding, so the earlier value was never read. Fix: read it, drop the dead line, or prefix `_x`. (ex: 10_fundamentals/02_variables.rs · 2026-06-15)
- **Derived `Debug` doesn't count as "using" a field** — printing a struct with `{:?}` still fires the `dead_code` warning ("fields are never read"); the compiler intentionally ignores derived impls during dead-code analysis (otherwise the lint could never flag a genuinely unused field). Silence it by reading a field in real code, or with `#[allow(dead_code)]`. (ex: 10_fundamentals/01_hello.rs · 2026-06-14)

## Corrections
<!-- Template:
### <date> — <topic>   (ex: <file>)
- **You had:** <the misconception, from your comments>.
- **Actually:** <the correct mental model>.
- **Takeaway:** <the one-line rule to remember>.
-->
_(empty — major corrections from reviews will be logged here)_

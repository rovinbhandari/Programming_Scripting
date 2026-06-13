// =============================================================
// Level 1 · Exercise 01 — Printing & format args
// =============================================================
//
// CONCEPT
//   Output text with the `println!` / `print!` macros and Rust's `{}` format
//   placeholders (named, positional, and the `{:?}` "debug" form).
//
// ANALOGIES
//   C# (tier 1):  Console.WriteLine($"Hello {name}");  Console.Write("no newline");
//   C / Python (tier 2):  C `printf("%d\n", x);`  ·  Python `print(f"{x}")`.
//   Plain concept: send formatted text to standard output.
//
// TASK
//   1. Print exactly:  Hello, Rust!
//   2. Make a `let name = "Ferris";` and print:  Hello, Ferris!  using a placeholder.
//   3. Make two integers and print one line:  3 + 4 = 7   (compute the sum, don't hardcode).
//   4. (stretch) Print a value using debug formatting `{:?}` and notice how it differs.
//
// EXPECTED OUTPUT (roughly)
//   Hello, Rust!
//   Hello, Ferris!
//   3 + 4 = 7
//
// HINTS
//   - Placeholders can be positional `{}` or capture a variable by name `{name}`.
//   - `print!` has no trailing newline; `println!` adds one.
//
// QUESTIONS TO PONDER  (answer in comments; mark yours with `// Q:`)
//   - Why does `println!` end in `!` — what makes it a *macro* and not a function?
//   - What's the difference between `{}` (Display) and `{:?}` (Debug)?
//
// Compile & run (Windows):  rustc 01_hello.rs && .\01_hello.exe
// -------------------------------------------------------------

fn main() {
    // TODO: write your solution here. Explain your thinking in comments,
    // and jot any questions with a `// Q:` prefix so I can spot them.
}

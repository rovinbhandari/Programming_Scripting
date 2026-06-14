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
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        Crabs don't say "Hello" — they say "Shello, World!"
//               So let's `print!` something and shell-ebrate. 🦀
//   Side quest: Print all three required lines using a SINGLE `println!`
//               (hint: `\n` is one newline inside the string). Then, from the
//               pair ("Hello", "Ferris"), print  Ferris, Hello!  using ONLY
//               positional args `{1}` and `{0}` — same data, brand-new order.
//   Easter egg: Try printing this tiny crab:   (\/)!_!(\/)
//               Gotcha: to put a literal backslash in a string you write `\\`.
//   Collectible: Secret ingredient 1 of 7 = 'O'. Every exercise in this level
//               hands you one letter; collect all seven to spell what iron
//               quietly does in damp air (and why this language is so named).
//
// Compile & run (Windows):  rustc 01_hello.rs && .\01_hello.exe
// -------------------------------------------------------------

fn main() {
    // TODO: write your solution here. Explain your thinking in comments,
    // and jot any questions with a `// Q:` prefix so I can spot them.
}

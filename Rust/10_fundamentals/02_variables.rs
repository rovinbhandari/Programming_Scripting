// =============================================================
// Level 1 · Exercise 02 — Variables: let, mut, shadowing, const
// =============================================================
//
// CONCEPT
//   Bindings are **immutable by default**. Opt into mutation with `mut`.
//   "Shadowing" re-declares a name with a fresh `let` (and may change its type).
//   `const` is a compile-time constant that always needs a type annotation.
//
// ANALOGIES
//   C# (tier 1):  `var x = 1;` is mutable; Rust's plain `let x = 1;` behaves like
//                 a `readonly`. `const N` ~ C# `const`.
//   C / Python (tier 2):  C `const int`; Python has no real immutability for locals.
//   Plain concept: who is allowed to change this value, and when.
//
// TASK
//   1. `let x = 5;` then try `x = 6;` — compile it, READ the error, then comment the
//      reassignment out and write in a comment what the compiler told you.
//   2. Make a `let mut y = 5;` and reassign it to 6. Print before and after.
//   3. Shadowing: `let s = "42";` then `let s = s.len();` (now `s` is a number).
//      Print the final `s`. Note in a comment that the *type* changed.
//   4. Declare `const MAX_SCORE: u32 = 100;` and print it.
//
// HINTS
//   - Shadowing creates a NEW binding; `mut` reuses the SAME binding.
//   - `const` names are SCREAMING_SNAKE_CASE by convention.
//
// QUESTIONS TO PONDER
//   - What's the practical difference between re-`let` shadowing and `mut` reassignment?
//   - Why must a `const` have an explicit type, while a `let` often doesn't?
//
// Compile & run (Windows):  rustc 02_variables.rs && .\02_variables.exe
// -------------------------------------------------------------

fn main() {
    // TODO: write your solution here. Explain your thinking in comments,
    // and jot any questions with a `// Q:` prefix so I can spot them.
}

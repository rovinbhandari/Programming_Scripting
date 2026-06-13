// =============================================================
// Level 1 · Exercise 03 — Scalar types & casting
// =============================================================
//
// CONCEPT
//   Rust's primitive scalars: integers (i8..i128/u8..u128, isize/usize),
//   floats (f32/f64), `bool`, and `char` (a 4-byte Unicode scalar).
//   Rust will NOT implicitly mix numeric types — you convert explicitly with `as`.
//
// ANALOGIES
//   C# (tier 1):  int/uint/long/double/bool/char; Rust forces explicit casts
//                 where C# might auto-widen.
//   C / Python (tier 2):  C fixed-width ints + `(double)` casts ·
//                 Python ints are arbitrary-precision (Rust's are fixed-width!).
//   Plain concept: a value's type fixes its size and the operations allowed on it.
//
// TASK
//   1. Declare one of each: an `i32`, a `u8`, an `f64`, a `bool`, a `char`. Print them.
//   2. Try to add an `i32` to an `f64` directly — READ the error, then fix it with `as`.
//   3. Cast: take `let n: i32 = 7;`, compute `n as f64 / 2.0`, print the result.
//   4. Cast a float back to int: `let k = 3.9_f64 as i32;` — print `k` and note in a
//      comment whether it rounds or truncates.
//
// HINTS
//   - Number literals can carry a type suffix: `5u8`, `3.0f32`, or use `_` like `1_000`.
//   - A `char` uses single quotes: `'A'`, `'🦀'`. A string uses double quotes.
//
// QUESTIONS TO PONDER
//   - Why is a Rust `char` 4 bytes, not 1 (think Unicode vs ASCII)?
//   - What happens on integer overflow — does it differ between a debug and release build?
//
// Compile & run (Windows):  rustc 03_scalar_types.rs && .\03_scalar_types.exe
// -------------------------------------------------------------

fn main() {
    // TODO: write your solution here. Explain your thinking in comments,
    // and jot any questions with a `// Q:` prefix so I can spot them.
}

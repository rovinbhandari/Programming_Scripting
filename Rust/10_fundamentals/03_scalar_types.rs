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
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        Time to get down to `bool`-siness, build some `char`-isma,
//               and go f64-and-furious with your casts.
//   Easter egg: DECODER. Each number below is a Unicode code point. Cast each
//               one `as char` and print them IN ORDER to reveal a hidden word —
//               no peeking; let the compiler do the talking:
//                   [82, 117, 115, 116, 97, 99, 101, 97, 110]
//   Collectible: Secret ingredient 3 of 7 = 'I'.
//
// Compile & run (Windows):  rustc 03_scalar_types.rs && .\03_scalar_types.exe
// Companion note:  03_scalar_types_notes.md  (as-casts & integer overflow — debug vs release)
// -------------------------------------------------------------

fn main() {
    let i32: i32 = 84;
    let u8: u8 = 5;
    let f64: f64 = -1.0044999;
    let bool: bool = true;
    let char: char = 'J';
    println!("i32: {}", i32);
    println!("u8: {}", u8);
    println!("f64: {}", f64);
    println!("bool: {}", bool);
    println!("char: {}", char);

    let i64: i64 = 99;
    // let sum = i32 + i64; // doesn't work because types are different and no auto casting.
    let sum: i64 = (i32 as i64) + i64;
    println!("sum: {sum}");

    // let sum = i32 + f64  // when ints didn't have a chance, this'd have absolutely none.
    let sum_as_i = i32 + (f64 as i32);
    let sum_as_f = (i32 as f64) + f64;
    // let sum_as_x = (i32 as f64) + (f64 as i32); // Q: doesn't compile as expected, yet why doesn't Rust Analyzer flag it?
    println!("sum_as_i: {}", sum_as_i);
    println!("sum_as_f: {}", sum_as_f);

    let n: i32 = 7;
    let div = n as f64 / 2.0;
    println!("div: {}", div);
    
    let k = 3.9 as i32; // truncated!
    println!("k: {}", k);
    let k = -3.9 as i32; // truncated!
    println!("k: {}", k);

    // Rust uses the modern Unicode that's 32 bits => 4 bytes.
    // if it didn't the following wouldn't have worked:
    let emoji = '🦀';
    println!("{emoji}");

    let arr: [u8; 9] = [82, 117, 115, 116, 97, 99, 101, 97, 110];
    let charr = arr.map(|c| c as char);
    charr.iter().for_each(|c| print!("{c}"));
    println!();

    // testing integer overflows...
    let i32_max = i32::MAX;
    println!("i32_max: {}", i32_max);
    let overflow = i32_max + 1; // my first panic!
    println!("overflow: {}", overflow);

}

// =============================================================
// Level 1 · Exercise 07 — Tuples & arrays
// =============================================================
//
// CONCEPT
//   Two fixed-size compound types:
//     - Tuple `(T1, T2, ...)`: a fixed group of POSSIBLY-DIFFERENT types. Access by
//       position `t.0`, `t.1`, or destructure: `let (a, b, c) = t;`.
//     - Array `[T; N]`: a fixed number `N` of the SAME type. Index with `a[i]`; length
//       via `a.len()`. Bounds are checked at runtime (out-of-range -> panic).
//
// ANALOGIES
//   C# (tier 1):  tuple ~ `(int, string) t = (1, "a");` (ValueTuple) ·
//                 array ~ `int[] a = {1, 2, 3};` (but Rust arrays are fixed-size).
//   C / Python (tier 2):  C fixed array `int a[5];` · Python tuple `(1, "a")` and list.
//   Plain concept: bundle a fixed set of values (mixed types) vs. a fixed run of one type.
//
// TASK
//   1. Make `let point: (i32, f64, char) = (3, 2.5, 'p');`. Print `point.0`. Then
//      destructure: `let (x, y, label) = point;` and print all three.
//   2. Make `let nums: [i32; 5] = [10, 20, 30, 40, 50];`. Print `nums[0]` and `nums.len()`.
//   3. Iterate `nums` with a `for` loop and print each element.
//   4. (stretch) Read `nums[10]` (out of bounds), run it, and note in a comment what
//      happens at runtime.
//
// HINTS
//   - Tuple index uses a DOT and a number: `point.0` (not `point[0]`).
//   - `[0; 5]` is shorthand for an array of five zeros.
//
// QUESTIONS TO PONDER
//   - When would you choose a tuple over an array, and vice versa?
//   - Why are both sizes fixed at COMPILE time (what does that buy you)?
//
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        A tuple is a fixed party with mixed guests; an array is a
//               uniform conga line. Tuple trouble, meet an array of sunshine.
//   Side quest: FINALE DECODER. Unscramble a word by indexing an array in a
//               given order. With:
//                   let scrambled = ['I', 'O', 'E', 'X', 'S', 'D', 'I'];
//                   let order     = [1, 3, 0, 5, 6, 4, 2];
//               loop over `order` and print `scrambled[i]` for each `i`. The
//               revealed word should match the seven secret ingredients you've
//               been collecting all level. 🦀
//   Collectible: Secret ingredient 7 of 7 = 'E' — it completes the word.
//               Congratulations: you have officially oxidised into a Rustacean!
//
// Compile & run (Windows):  rustc 07_tuples_arrays.rs && .\07_tuples_arrays.exe
// Companion note:  07_tuples_arrays_notes.md  (fixed-size compounds; bounds: compile-time vs runtime)
// -------------------------------------------------------------

fn main() {
    let point: (i32, f64, char) = (3, 2.5, 'p');
    println!("{}", point.0);
    let (x, y, label) = point;
    println!("{}, {}, {}", x, y, label);
     
    let nums = [10, 20, 30, 40, 50];
    println!("{}", nums[0]);
    println!("{}", nums.len());

    // Task 3: Iterate array
    for num in nums {
        println!("{}", num);
    }
    
    // Task 4: Out of bounds access
    // let out_of_bounds = nums[10];  // compiler failed with: error: this operation will panic at runtime

    // Tuple is an easy way to represent a complex type or a value with multiple-type dimensions
    // Array is mainly for many values of the same type.

    // Fixing size at compile time ensures better capturing of out of bounds indexes during compilation.

    let scrambled = ['I', 'O', 'E', 'X', 'S', 'D', 'I'];
    let order     = [1, 3, 0, 5, 6, 4, 2];
    for i in order 
    {
        print!("{}", scrambled[i]);
    }
}

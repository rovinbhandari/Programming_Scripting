// =============================================================
// Level 1 · Exercise 06 — Loops: loop / while / for, ranges
// =============================================================
//
// CONCEPT
//   Three loop forms:
//     - `loop { ... }`      infinite; exit with `break`, and `break value` can RETURN a value.
//     - `while cond { ... }`  run while a bool holds.
//     - `for x in iter { ... }`  iterate anything iterable, including ranges `0..n` (end-
//        exclusive) and `0..=n` (inclusive).
//
// ANALOGIES
//   C# (tier 1):  `while`, `do/while`, classic `for`, and `foreach`. Rust's `for ... in`
//                 is like `foreach` — there is no C-style `for(i=0; i<n; i++)`.
//   C / Python (tier 2):  C `for(...)` vs Python `for x in range(n)` (very close to Rust).
//   Plain concept: repeat work; sometimes carry a result out of the loop.
//
// TASK
//   1. `loop`: count up from 1; when you reach 5, `break` and RETURN the value into a
//      variable, e.g.  let found = loop { ... break i * 10; };  then print `found`.
//   2. `while`: count DOWN from 3 to 1, printing each, then "liftoff!".
//   3. `for`: print each number in `1..=5` (inclusive).
//   4. `for`: iterate the array `[10, 20, 30]` and print each element.
//   5. (stretch) Nested loops with a LABEL: `'outer: loop { ... break 'outer; }`.
//
// HINTS
//   - `0..n` excludes `n`; `0..=n` includes it.
//   - `break value;` only carries a value out of a `loop` (not `while`/`for`).
//
// QUESTIONS TO PONDER
//   - How is `for i in 0..n` different (safety-wise) from C#'s `for (int i...)`?
//   - When would you reach for `loop` instead of `while`?
//
// Compile & run (Windows):  rustc 06_loops.rs && .\06_loops.exe
// -------------------------------------------------------------

fn main() {
    // TODO: write your solution here. Explain your thinking in comments,
    // and jot any questions with a `// Q:` prefix so I can spot them.
}

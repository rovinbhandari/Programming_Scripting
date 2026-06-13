// =============================================================
// Level 1 · Exercise 05 — Control flow: if / else as an expression
// =============================================================
//
// CONCEPT
//   `if cond { ... } else if cond { ... } else { ... }`. The condition must be a real
//   `bool` (no "truthy" ints). Because `if` is an **expression**, you can assign its
//   result to a variable — both arms must produce the SAME type.
//
// ANALOGIES
//   C# (tier 1):  the value form replaces the ternary: `var y = c ? a : b;`
//                 becomes `let y = if c { a } else { b };`.
//   C / Python (tier 2):  C requires `int` truthiness; Rust does not.
//                 Python's value form is `a if cond else b`.
//   Plain concept: choose a branch; optionally let the chosen branch yield a value.
//
// TASK
//   1. Given `let n = -4;`, print whether it is "positive", "negative", or "zero"
//      using `if / else if / else`.
//   2. Assign from an `if` expression:  let label = if n % 2 == 0 { "even" } else { "odd" };
//      then print `label`.
//   3. Try making the two arms different types (e.g. one `"even"`, one `0`), compile,
//      READ the error, then revert and explain it in a comment.
//   4. (stretch) Try `if 1 { ... }` (a non-bool condition), read the error, revert.
//
// HINTS
//   - `else if` chains are fine; an `if` used as a value usually needs an `else`.
//   - Comparison/logic: `==  !=  <  >  <=  >=  &&  ||  !`.
//
// QUESTIONS TO PONDER
//   - Why doesn't Rust have a `?:` ternary operator at all?
//   - Why must both arms of a value-producing `if` have the same type?
//
// Compile & run (Windows):  rustc 05_control_flow.rs && .\05_control_flow.exe
// -------------------------------------------------------------

fn main() {
    // TODO: write your solution here. Explain your thinking in comments,
    // and jot any questions with a `// Q:` prefix so I can spot them.
}

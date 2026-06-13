// =============================================================
// Level 1 · Exercise 04 — Functions & the expression/statement rule
// =============================================================
//
// CONCEPT
//   `fn name(param: Type) -> ReturnType { ... }`. The **last expression** in a block
//   (with NO trailing semicolon) is the block's value — so functions return their tail
//   expression without the `return` keyword. Adding a `;` turns it into a statement
//   that yields nothing (`()`), the "unit" type.
//
// ANALOGIES
//   C# (tier 1):  `int Square(int n) => n * n;` — but in Rust the tail expression
//                 returning is the *default*, not special syntax.
//   C / Python (tier 2):  C/Python always need an explicit `return`.
//   Plain concept: an expression produces a value; a statement performs an action.
//
// TASK
//   1. Write `fn square(n: i32) -> i32` that returns `n * n` using a TAIL expression
//      (no `return`, no `;` on the last line). Call it from `main` and print the result.
//   2. Write `fn add(a: i32, b: i32) -> i32` and print `add(3, 4)`.
//   3. Write a function that uses an EARLY `return` for one case (e.g. return 0 if input
//      is negative) and a tail expression otherwise.
//   4. Inside `main`, assign from a block expression:
//          let x = { let a = 2; a + 1 };   // x == 3
//      Print `x`. Then add a `;` after `a + 1`, recompile, and note the error in a comment.
//
// HINTS
//   - Every parameter needs a type; the return type after `->` is required if you return
//     a value.
//   - Forgetting the function's `-> i32` while returning an int is a classic first error.
//
// QUESTIONS TO PONDER
//   - In Rust, what exactly is the difference between a *statement* and an *expression*?
//   - What does adding a `;` to a function's last line do to what the function returns?
//
// Compile & run (Windows):  rustc 04_functions.rs && .\04_functions.exe
// -------------------------------------------------------------

// TODO: define your functions up here (e.g. `fn square(...) -> i32 { ... }`)

fn main() {
    // TODO: call your functions, print results, and explain your reasoning in comments.
    // Mark questions with `// Q:` so I can spot them.
}

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
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        In Rust the `return` on investment is the tail expression —
//               no `;` strings attached.
//   Side quest: Write `fn parity(n: i32) -> char` that yields 'E' for even and
//               'O' for odd as a SINGLE tail `if` expression — no `return`, and
//               no `;` on the last line. Brain-twister: write a second fn that
//               uses BOTH an early `return` and a tail expression — when is each one reached?
//   Collectible: Secret ingredient 4 of 7 = 'D'. (D is for: *don't* add that
//               sneaky trailing semicolon.)
//
// Compile & run (Windows):  rustc 04_functions.rs && .\04_functions.exe
// Companion note:  04_functions_notes.md  (expression vs statement — `;` discards a value)
// -------------------------------------------------------------

fn square(n: i32) -> i32
{
    n * n
}

fn nthchar(s: &str, n: usize) -> char
{
    if n >= s.len() {
        return ' ';
    }

    let mut i = 0;
    let mut nth: char = ' ';
    for c in s.chars()
    {
        if i == n
        {
            nth = c;
        }
        
        i += 1;
    }

    nth
}

fn add(a: i32, b: i32) -> i32
{
    a + b
}

fn parity(n: i32) -> char
{
    if n % 2 == 0
    {
        'E'
    }
    else 
    {
        'O'
    }
}

fn main() {
    let num = 5;
    let sq = square(num);
    println!("{num}^2={sq}");

    let (a, b) = (3, 4);
    let s = add(a, b);
    println!("{a}+{b}={s}");

    let s = "blahblah";
    let valid_nthchar = nthchar(s, num as usize);
    println!("{num}th char of {s} = {valid_nthchar}");
    let num2 = num as usize * 2;
    let invalid_nthchar = nthchar(s, num2);
    println!("{num2}th char of {s} = {invalid_nthchar}");

    let x = { let a = 2; a + 1 };   // if no return value, then it's construed as a function returning () (E0277)
    println!("{x}");

    // statement is that ends in ';', whereas expression is any operand+operator (Q: is it correct enough?)
    // if there's a ';' to a fn's return, it makes the function a () type.

    println!("{num} is {}", parity(num));
    println!("{num2} is {}", parity(num2 as i32));
}

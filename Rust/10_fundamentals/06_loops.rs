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
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        We're in this for the `loop` haul: `while` away the time,
//               then `for`-ge ahead.
//   Side quest: Payoff time — take your FizzBuzz from exercise 05 and LOOP it
//               over `1..=15` with a `for`. Then use `loop { ... break value }`
//               to find the first `n` whose `n * n > 50`, and print it.
//   Collectible: Secret ingredient 6 of 7 = 'S'. (Spelling drifts by ocean —
//               swap this 'S' for a 'Z' and you'd have the American version.)
//
// Compile & run (Windows):  rustc 06_loops.rs && .\06_loops.exe
// Companion note:  06_loops_notes.md  (loop/while/for, break-with-value, ranges, labels)
// -------------------------------------------------------------

fn main() {
    let mut i = 1;
    let found = 
        loop 
        {
            if i == 5
            {
                break i * 10;
            }
            i += 1;
        };
    println!("{found}");

    let mut j = 3;
    while j > 0
    {
        println!("{j}...");
        j -= 1;
    }
    println!("liftoff!");

    for k in 1..=5
    {
        println!("{k}")
    }

    for l in (1..=3).map(|x| x*10)
    {
        println!("{l}");
    }

    let mut m = 100..=500;
    let n = 50..150;
    let any_n_in_m = 'outer: loop 
        {
            let mnext = m.next();
            if mnext.is_none()
            {
                break false;
            }
            else 
            {
                let mut n_ = n.clone();
                'inner: loop
                {
                    let n_next = n_.next();
                    if n_next.is_none()
                    {
                        break;
                    }
                    else if Some(n_next).unwrap() == Some(mnext).unwrap()
                    {
                        break 'outer true;
                    }
                }
            }
        };
    println!("n found in m? {any_n_in_m}");

    // for i in x..y seems to have more well-predictable exit condition than a vanilla for (i = x; i < y; )
    // while COND is better than loop { ... } when the condition COND should be checked prior to starting looping.

    for o in 1..=15
    {
        if o % 15 == 0
        {
            println!("FizzBuzz");
        }
        else if o % 3 == 0
        {
            println!("Fizz");
        }
        else if o % 5 == 0
        {
            println!("Buzz");
        }
        else 
        { 
            println!("{o}");
        };
    }

    let mut p = 1;
    let n2gt50 = loop 
        {
            if p * p > 50
            {
                break p;
            }
            p += 1;
        };
    println!("{n2gt50}");

}

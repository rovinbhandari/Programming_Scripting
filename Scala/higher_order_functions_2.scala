/*
	to find : f(a) + f(a+1) + .... + f(b)
		where f can be chosen from a number of choices defined.
*/

// this approach makes use of Anonymous Functions.


object hof2
{
	def sum(f : Int => Int, a: Int, b: Int): Int = if(a > b) 0 else f(a) + sum(f, a + 1, b)
	
	def square(q : Int, w : Int) : Int = sum((x: Int) => x * x, q, w)

	def identity(q : Int, w : Int) : Int = sum((x: Int) => x, q, w)
	
	def factorial(q : Int, w : Int) : Int = sum((x: Int) => fact(x), q, w)
	
	def fact(x : Int) : Int = if(x == 0) 1 else x * fact(x - 1)
	
	// recursion of anonymous functions is not possible (duh!)

	def main(args : Array[String]) : Unit =
	{
		var a = Console.readInt();
		var b = Console.readInt();
		var c = Console.readInt();
		if(c == 1) Console.println(square(a, b)) else if(c == 2) Console.println(identity(a, b)) else Console.println(factorial(a, b))
	}
}

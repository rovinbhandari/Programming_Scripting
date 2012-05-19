/*
	to find : f(a) + f(a+1) + .... + f(b)
		where f can be chosen from a number of choices defined.
*/


object hof
{
	def sum(f : Int => Int, a: Int, b: Int): Int = if(a > b) 0 else f(a) + sum(f, a + 1, b)
	
	def powerof2(x : Int) : Int = if(x == 0) 1 else 2 * powerof2(x - 1)

	def square(x : Int) : Int = x * x
	
	def factorial(x : Int) : Int = if(x == 0) 1 else x * factorial(x - 1)
	
	def main(args : Array[String]) : Unit =
	{
		var a = Console.readInt();
		var b = Console.readInt();
		var c = Console.readInt();
		if(c == 1) Console.println(sum(powerof2, a, b)) else if(c == 2) Console.println(sum(square, a, b)) else Console.println(sum(factorial, a, b))
	}
}

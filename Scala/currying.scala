/*
	to find : f(a) + f(a+1) + .... + f(b)
		where f can be chosen from a number of choices defined.
*/

// this approach makes use of Currying


object currying
{
	def sum(f : Int => Int) : (Int, Int) => Int = 
	{
		def sum_param(a : Int, b : Int) : Int = if (a > b) 0 else f(a) + sum_param(a + 1, b)
		sum_param
	}
	
	def powerof2(x : Int) : Int = if(x == 0) 1 else 2 * powerof2(x - 1)

	def square(x : Int) : Int = x * x
	
	def factorial(x : Int) : Int = if(x == 0) 1 else x * factorial(x - 1)
		
	def sumpowerof2 = sum(powerof2)
	
	val sumsquare = sum(x => x * x)
	// with 'val', 'sumsquare' has been made a constant; it cannot be modified now unlike with 'def'.
		
	def sumfactorial = sum(factorial)
	
	def main(args : Array[String]) : Unit =
	{
		var a = Console.readInt();
		var b = Console.readInt();
		var c = Console.readInt();
		if(c == 1) Console.println(sumpowerof2(a, b)) else if(c == 2) Console.println(sumsquare(a, b)/*this statement is equivalent to : sum(x => x * x)(a, b) OR (sum(x => x * x))(a, b)*/) else Console.println(sumfactorial(a, b))
	}
}

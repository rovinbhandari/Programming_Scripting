/*
	to find the square root of a number 'n' using Newton's method (involving an initial guess 'g') as :
		g = (g + n/g)/2 until g*g ~ n
*/

// this approach also calculates for very small and very large numbers unlike the previous version.


object sqrt2
{
	def guess_iteration(guess : Double, num : Double) : Double = 
	{
		if(Math.abs(guess * guess - num) < (num / 1000))
			guess
		else
			guess_iteration((guess + num / guess) / 2, num)
	}
	
	def main(args : Array[String]) : Unit =
	{
		var num = Console.readDouble();
		Console.println(guess_iteration(1.0, num))
	}
}

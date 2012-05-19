/*
	The following class is a generic class for operations on Complex Numbers.
	The valid operations are :
		~ : Conjugate
			z~
		|| : Absolute value
			z||
		||| : Square of absolute value
			z|||
		+ : Sum
			z1 + z2
			z1 + r		(r is a Real Number)
		- : Difference
			z1 - z2
		* : Product
			z1 * z2
			z1 * r		(r is a Real Number)
		/ : Quotient
			z1 / z2
			z / r		(r is a Real Number)
*/


class Complex(x : Double, y : Double)
{
	val real : Double = x
	val imag : Double = y
	
	def ~ : Complex = new Complex(real, (-1) * imag)
	
	def || : Double = Math.sqrt(real * real + imag * imag)
	
	def ||| : Double = real * real + imag * imag
	
	def +(postop : Complex) : Complex = new Complex(real + postop.real, imag + postop.imag)
	/* it doesn't matter even if the above were written as:
		def sum(postop : Complex) : Complex = new Complex(real + postop.real, imag + postop.imag)
	and called as z1 sum z2 */
	
	def +(postop : Double) : Complex = new Complex(real + postop, imag)
	
	def -(postop : Complex) : Complex = new Complex(real - postop.real, imag - postop.imag)
	
	def *(postop : Complex) : Complex = new Complex(real * postop.real - imag * postop.imag, real * postop.imag + imag * postop.real)
	
	def *(postop : Double) : Complex = new Complex(real * postop, imag * postop)
	
	def /(postop : Double) : Complex = new Complex(real / postop, imag / postop)
	
	def /(postop : Complex) : Complex = ((this * (postop~)) / (postop|||))
	
	override def toString : String = "(" + real + ") + (" + imag + ")i\n"
	
}

object cplx
{
	def main(args : Array[String]) : Unit =
	{
		val a : Complex = new Complex(Console.readDouble(), Console.readDouble());
		val b : Complex = new Complex(Console.readDouble(), Console.readDouble());
		
		val c = (a * a * a) + (b * b * b) + (a * a * b * 3.0) + (a * b * b * 3.0) + (a * b * (a - (b~)) * ((a~) + b) * 3.0);
		
		Console.println("\nAns = " + c.toString)
	}
}

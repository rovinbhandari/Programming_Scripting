

/*
	
	Template :
	
def p(x : ) :  = 
{
	
}
val pin :  = ;
println("\n p(" + pin + ") = " + p(pin));

*/

	

// isPrime				// needs improvement
def p31(x : Int) : Boolean = 
{
	val u : Int = Math.floor(Math.sqrt(x)).asInstanceOf[Int];		// explicit type-casting of Math.floor from Double to Int
	def nooffactors(i : Int, count : Int) : Int = if(i >= u && x % i == 0) 1 else if(i >= u && x % i != 0) count else if(x % i == 0) 1 else nooffactors(i + 1, count)
	if(x == 0 || x == 1) false else if(x == 2) true else (nooffactors(2, 0) == 0)
}
val p31in : Int = 2;
println("\n p31(" + p31in + ") = " + p31(p31in));

// gcd (Euclid's)
def p32(x : (Int, Int)) : Int = if(x._2 == 0) x._1 else p32(x._2, x._1 % x._2)
val p32in = Tuple2(36, 27);
println("\n p32(" + p32in + ") = " + p32(p32in));

// coprime
def p33(x : (Int, Int)) : Boolean = if(p32(x._1, x._2) == 1) true else false
val p33in = Tuple2(81, 64);
println("\n p33(" + p33in + ") = " + p33(p33in));

// Euler's totient
def p34(x : Int) : Int = 
{
	def phi(i : Int, count : Int) : Int = if(i == 0) count else if(p33(x, i)) phi(i - 1, count + 1) else phi(i - 1, count)
	phi(x, 0)
}
val p34in : Int = 10;
println("\n p34(" + p34in + ") = " + p34(p34in));

// prime factors (increasing order)
def p35(x : Int) : List[Int] = 
{
	def prfac(n : Int, i : Int, l : List[Int]) : List[Int] = if(i == 1) l else if(p31(i) && n % i == 0) prfac(n / i, i, i :: l) else prfac(n, i - 1, l)
	prfac(x, x, List())
}
val p35in : Int = 180 * 7;
println("\n p35(" + p35in + ") = " + p35(p35in));

// prime factors (increasing order + mapped to respective frequencies)
/*
def p36(x : Int) : List[(Int, Int)] = 
{
	val completelist : List[Int] = p35(x);
	complete
}
val pin :  = ;
println("\n p(" + pin + ") = " + p(pin));

// Euler's totient (improved)
def p37(x : ) :  = 
{
	
}
val pin :  = ;
println("\n p(" + pin + ") = " + p(pin));

// Comparison of the two methods of calculaing Euler's totient.
def p38(x : ) :  = 
{
	
}
val pin :  = ;
println("\n p(" + pin + ") = " + p(pin));
*/

// list of prime numbers in a specified range.
def p39(x : (Int, Int)) : List[Int] = List.range(x._1, x._2) filter p31
val p39in = Tuple2(2, 45);
println("\n p39(" + p39in + ") = " + p39(p39in));

// list of x number of prime numbers.
def p39m(x : Int) : List[Int] = 
{
	def listpr(i : Int, j : Int, l : List[Int]) : List[Int] = if(j > x) l else if(p31(i)) listpr(i + 1, j + 1, i :: l) else listpr(i + 1, j, l)
	listpr(2, 1, List())
}

// Goldbach's conjecture
def p40(x : Int) : (Int, Int) = 
{
	def iteratelist(i : Int, k : Int, l : List[Int]) : Int = if(i >= k) 0 else if((x - l(i)) > 0 && p31(x - l(i))) l(i) else iteratelist(i + 1, k, l)
	def twoprimes(j : Int) : (Int, Int) = 
	{
		val v : Int = iteratelist(0, j, p39m(j));
		if(v == 0) twoprimes(j + 5) else Tuple2(v, x - v)
	}
	if(x % 2 == 0 && x > 2) twoprimes(5) else Tuple2(666, 666)
}
val p40in : Int = 4;
println("\n p40(" + p40in + ") = " + p40(p40in));

// list of Goldbach's compositions
def p41(x : (Int, Int)) : List[(Int, Int, Int)] = 
{
	def iteraterange(i : Int, l : List[(Int, Int, Int)]) : List[(Int, Int, Int)] = 
	{
		val p = p40(i);
		if(i > x._2) l else if(i % 2 == 0) iteraterange(i + 1, Tuple3(i, p._1, p._2) :: l) else iteraterange(i + 1, l)
	}
	iteraterange(x._1, List())
}
val p41in = Tuple2(3, 30);
println("\n p41(" + p41in + ") = " + p41(p41in));


println();

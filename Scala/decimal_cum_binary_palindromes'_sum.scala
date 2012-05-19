/*
	Program to find the sum of numbers which are palindromic in boh he decimal and he binary form.
*/

val listdec : List[Int] = gendecpal();
val listbin : List[String] = tobinary(listdec);

def gendecpal() : List[Int] = 
{
	def gendef(n : Int, i : (Int, Int), j : (Int, Int, Int), k : (Int, Int, Int)) : Int = (i._1 + 1) * (1 + i._2 * Math.pow(10, n - 1).asInstanceOf[Int]) + j._3 * j._1 * (10 + j._2 * Math.pow(10, n - 2).asInstanceOf[Int]) + k._3 * k._1 * (100 + k._2 * Math.pow(10, n - 3).asInstanceOf[Int])
	def gen(n : Int, iter : Int, l : List[Int]) : List[Int] = 
	n match
	{
		case 1 => if(iter < 9) gen(n, iter + 1, gendef(n, Tuple2(iter, 0), Tuple3(0, 0, 0), Tuple3(0, 0, 0)) :: l) else gen(n + 1, 0, l)
		case 2 => if(iter < 9) gen(n, iter + 1, gendef(n, Tuple2(iter, 1), Tuple3(0, 0, 0), Tuple3(0, 0, 0)) :: l) else gen(n + 1, 0, l)
		case 3 => if(iter < 90) gen(n, iter + 1, gendef(n, Tuple2(iter / 10, 1), Tuple3(iter % 10, 0, 1), Tuple3(0, 0, 0)) :: l) else gen(n + 1, 0, l)
		case 4 => if(iter < 90) gen(n, iter + 1, gendef(n, Tuple2(iter / 10, 1), Tuple3(iter % 10, 1, 1), Tuple3(0, 0, 0)) :: l) else gen(n + 1, 0, l)
		case 5 => if(iter < 900) gen(n, iter + 1, gendef(n, Tuple2(iter / 100, 1), Tuple3((iter / 10) % 10, 1, 1), Tuple3(iter % 10, 0, 1)) :: l) else gen(n + 1, 0, l)
		case 6 => if(iter < 900) gen(n, iter + 1, gendef(n, Tuple2(iter / 100, 1), Tuple3((iter / 10) % 10, 1, 1), Tuple3(iter % 10, 1, 1)) :: l) else gen(n + 1, 0, l)
		case _ => l
	}
	gen(1, 0, List())
}

def tobinary(l : List[Int]) : List[String] = 
{
	def dec2bin(n : Int, s : String) : String = if(n == 0 || n == 1) n + s else dec2bin(n / 2, (n % 2) + s)
	def iteratelist(i : Int, binl : List[String]) : List[String] = if(i < 0) binl else iteratelist(i - 1, dec2bin(l(i), "") :: binl)
	iteratelist(l.length - 1, List())
}

def sumdecbinpal(ldec : List[Int], lbin : List[String]) : Int = 
{
	def isbinpal(s : String) : Boolean = s == s.reverse.mkString
	def iteratelists(i : Int, sum : Int) : Int = if(i >= 0) if(isbinpal(lbin(i))) iteratelists(i - 1, sum + ldec(i)) else iteratelists(i - 1, sum) else sum
	iteratelists(ldec.length - 1, 0)
}

println("\nSum = " + sumdecbinpal(listdec, listbin));

/*
	Rovin Bhandari
	13/10/2011
	
	FCTRL2
*/

import java.io.*;
import java.math.BigInteger;

class fctrl2
{
	static BigInteger mem[];
	static final int memsize = 101;
	
	static int i;
	static int maxcalc;
	
	static BigInteger fac(int x)
	{
		if(x <= maxcalc)
			return mem[x];
		else
		{
			i = maxcalc;
			while(++i <= x)
				mem[i] = mem[i - 1].multiply(BigInteger.valueOf(i));
			maxcalc = x;
			return mem[x];
		}
	}
	
	public static void main(String args[]) throws IOException
	{
		mem = new BigInteger[memsize];
		mem[0] = mem[1] = BigInteger.valueOf(1);
		maxcalc = 1;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0)
			System.out.println(fac(Integer.parseInt(br.readLine())));
	}
}

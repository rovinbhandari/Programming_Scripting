/*
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

	What is the 10001st prime number?
*/

import java.lang.Math;
class r007
{
	public static void main(String args[])
	{
		int count = 8;
		long prime = 19;
		long ri;
		long d;
		boolean b;
		for(long i = 23; i < 999999; i++)
		{
		 	ri = (long) Math.sqrt(i);
		 	d = 2;
		 	b = true;
		 	while(d <= ri)
		 	{
		 		if((i % d ) == 0)
		 		{
		 		 	b = false;
		 		 	break;
		 		}
		 		d++;
		 	}
		 	if(b)
		 	{
		 	 	count++;
		 	 	prime = i;
		 		
		 	}
		 	if(count == 10001)
		 	{
		 		System.out.println("\n\n\n\t ==>  10001st prime is " + prime);
		 		break;
		 	}
		 }
	}
}		

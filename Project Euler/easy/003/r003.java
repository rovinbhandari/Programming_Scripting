/*
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/

import java.lang.Math;
class r003
{
 	public static void main(String args[])
	{
		long i, j, lpf, c, ri;
  		c = 600851475143l;
  		boolean b;
  		i = 11l;
  		lpf = 1l;
  		ri = 1l;
  		while(i < c)
 		{
   			i++;
   			if((c % i) == 0)
   			{
   			 	c /= i;
   			 	j = 2l;
   	  		 	b = true;
   	  		 	ri = (long) Math.sqrt(i);
   	  		 	while(j < ri)
    	  		 	{
     					if((i % j) == 0)
     					{
      						b = false;
      						break;
     					}
     					j++;
    	 		 	}
    			 	if(b)
    			 	{
     		 			lpf = i;
    			 	}
   			 }
  		}
  		System.out.print("\n\tLargest prime factor of 600851475143 is " + lpf);
 	}
}

/*        PROGRAM TO TEST WHETHER AN INTEGER IS PRIME OR COMPOSITE          */

/*

  AN INTEGER n CAN BE TESTED TO BE A PRIME NUMBER OR NOT BY THE FOLLOWING
  THREE METHODS :
   1 ==>  DIVIDE THE NUMBER BY NUMBERS FROM 2 TO (n - 1) .
   2 ==>  DIVIDE THE NUMBER BY NUMBERS FROM 2 TO (n / 2) .
   3 ==>  DIVIDE THE NUMBER BY NUMBERS FROM 2 TO (sq.rt of n) .

  SINCE METHOD 3 IS THE FASTEST, THE FOLLOWING PROGRAM IS BASED ON METHOD 3 ::

*/
                                                      
import java.io.*;
import java.lang.Math;
class fortyeight
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("-------------PROGRAM TO TEST WHETHER AN INTEGER IS PRIME OR COMPOSITE-----------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter an integer :");
  System.out.print("==> ");
  long a = Long.parseLong(x.readLine());
  double b = Math.sqrt(a);
  long c = 2;
  long d = a;
  System.out.println("");
  if((d != 0) && (d != 1))
  {
   while(c < b)
   {
    if((a % c) == 0)
    {
     System.out.println("The number " + d + " is a COMPOSITE NUMBER.");
     System.out.println("");
     System.out.println("--------------------------------------------------------------------------------");
     return;
    }
    else
    {
     c++;
    }
   }
   System.out.println("The number " + d + " is a PRIME NUMBER.");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
  }
  else if(d == 1)
  {
   System.out.println("ONE is neither a prime nor a composite number.");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
  }
  else
  {
   System.out.println("Wrong entry...!");
   System.out.println("Please enter an integer greater than ZERO.");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
  }
 }
}

/*PROGRAM TO FIND WHETHER THE ENTERED INTEGER IS AN ARMSTRONG NUMBER OR NOT */
import java.io.*;
class fortyfour
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("---PROGRAM TO FIND WHETHER THE ENTERED INTEGER IS AN ARMSTRONG NUMBER OR NOT---");
  System.out.println("");
  System.out.println("Enter an integer :");
  System.out.print("==> ");
  long a = Long.parseLong(x.readLine());
  long z = a;
  long sum = 0;
  while( a > 0 )
  {
   long s = a % 10;
   sum = sum + ( s * s * s );
   a = a / 10;
  }
  System.out.println("");
  if( z == sum )
  {
   System.out.println("The integer entered is an ARMSTRONG NUMBER.");
  }
  else
  {
   System.out.println("The integer entered is not an ARMSTRONG NUMBER.");
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
  System.out.println("");
 }
}


/*


  There are only six Armstrong Numbers in the number system.
  These are :
  ==> 0
  ==> 1
  ==> 153
  ==> 370
  ==> 371
  ==> 407

*/

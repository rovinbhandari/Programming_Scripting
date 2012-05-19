/*              PROGRAM TO REVERT DIGITS OF AN INTEGER ENTERED              */
import java.io.*;
class fortyone
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter an integer :");
  System.out.print("==> ");
  long a = Long.parseLong(x.readLine());
  long z = 0;
  while( a > 0 )
  {
   long s = a % 10;
   z = ( z * 10 ) + s;
   a = a / 10;
  }
  System.out.println("");
  System.out.println("Reversed digits of the integer entered :");
  System.out.println(z);
  System.out.println("");
 }
}

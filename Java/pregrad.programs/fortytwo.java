/*      PROGRAM TO FIND THE SQUARE SUM OF DIGITS OF AN INTEGER ENTERED      */
import java.io.*;
class fortytwo
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter an integer :");
  System.out.print("==> ");
  long a = Long.parseLong(x.readLine());
  long sum = 0;
  while( a > 0 )
  {
   long s = a % 10;
   sum = sum + ( s * s);
   a = a / 10;
  }
  System.out.println("");
  System.out.println("Square sum of digits of the integer entered :");
  System.out.println(sum);
  System.out.println("");
 }
}

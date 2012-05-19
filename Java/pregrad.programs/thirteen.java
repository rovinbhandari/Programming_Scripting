/*                                 PATTERNS                                 */
import java.io.*;
class thirteen
{
 public static void main(String args[]) throws IOException
 {
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader x = new BufferedReader(isr);
  System.out.println("Enter an integer value : ");
  int n = Integer.parseInt(x.readLine());
  for(int i=1; i<=n; i++)
  {
   for(int j=1; j<=(n-i); j++)
   System.out.print(" ");
   for(int k=1; k<=(2*i-1); k++)
   System.out.print("*");
   System.out.println(" ");
  }
 }
}

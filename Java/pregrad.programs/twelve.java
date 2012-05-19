/*                                 PATTERN                                  */
import java.io.*;
class twelve
{
 public static void main(String args[]) throws IOException
 {
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader x = new BufferedReader(isr);
  System.out.println("Enter an integer value : ");
  int n = Integer.parseInt(x.readLine());
  int j;
  for(int i = 1; i <= n; i++)
  {
   for(j = 1; j <= (n-i); j++)
   {
    System.out.print(" ");
   }
   System.out.println(i + " ");
  }
 }
}

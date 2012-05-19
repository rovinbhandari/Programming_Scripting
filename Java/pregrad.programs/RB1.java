/* sum of series of the type :

   t(n) = 1/(1+2+3+...+n)
*/
import java.io.*;
class RB1
{
 public static void main(String args[]) throws IOException
 {
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader br = new BufferedReader(isr);
  System.out.println("sum of series of the type : t(n) = 1/(1+2+3+...+n)");
  System.out.println("Enter a natural number :");
  int n = Integer.parseInt(br.readLine());
  double d;
  double s = 0.0d;
  for(int j = 1;j <= n;j++)
  {
   d = 0.0d;
   for(int i = 1;i <= j;i++)
   {
    d = d + (double) i;
   }
   s = s + 1.0/d;
  }
  System.out.println("sum is : " + s);
 }
}



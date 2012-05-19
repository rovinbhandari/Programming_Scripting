/*                                PATTERNS                                 */
import java.io.*;
class ten
{
 public static void main(String args[]) throws IOException
 {
  char c = 219;
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader x = new BufferedReader(isr);
  System.out.println("Enter an integer value : ");
  int n = Integer.parseInt(x.readLine());
  int r;
  for(int i=1; i<=n; i++)
  {
   for(int j=1; j<=i; j++)
   {
    System.out.print(c);
   }
   r = i%170;
   if (r!=0)
   {
    System.out.println("");
   }
  }
 }
}

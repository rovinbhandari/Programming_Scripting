//                                PATTERN
import java.io.*;
class RB6
{
 public static void main(String args[]) throws IOException
 {
  char c = 219;
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader br = new BufferedReader(isr);
  System.out.print("\n  Enter an integer : ");
  int n = Integer.parseInt(br.readLine());
  for(int i = 1;i <= n;i++)
  {
   for(int j = 1;j <= n - i;j++)
   {
    System.out.print(" ");
   }
   for(int k = 1;k <= 2 * i - 1;k++)
   {
    System.out.print(c);
   }
   System.out.println("");
  }
 }
}


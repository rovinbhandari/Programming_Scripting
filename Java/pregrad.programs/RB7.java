//                                PATTERN
import java.io.*;
class RB7
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
   for(int j = 1;j <= n;j++)
   {
    if(n % 2 == 0)
    {
     if((j == n/2) || (j == n/2 + 1) || (i == n/2) || (i == n/2 + 1))
     {
      System.out.print(" ");
     }
     else
     {
      System.out.print(c);
     }
    }
    else
    {
     if((j == n/2 + 1) || (i == n/2 + 1))
     {
      System.out.print(" ");
     }
     else
     {
      System.out.print(c);
     }
    } 
   }
   System.out.println("");
  }
 }
}


//                                PATTERN
import java.io.*;
class RB5
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
    if((j + i) % 2 != 0)
    {           
     System.out.print(" ");
    }
    else
    {
     System.out.print(c);
    }
   }
   System.out.println("");
  }
 }
}


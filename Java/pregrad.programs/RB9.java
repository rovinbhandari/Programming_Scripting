import java.io.*;
class RB9
{
 public static void main(String args[]) throws IOException
 {
  char c = 219;
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  System.out.print(" Enter a natural number : ");
  int n = Integer.parseInt(br.readLine());
  System.out.println("");
  for(int i = 1;i <= n;i++)
  {
   for(int j = 1;j <= (i - 1);j++)
   {
    System.out.print(" ");
   }
   System.out.print(c);
   for(int k = 1;k <= 2 * (n - i);k++)
   {
    System.out.print(" ");
   }
   System.out.println(c);
  }
 }
}

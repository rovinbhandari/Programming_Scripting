//                              RECTANGLE
import java.io.*;
class RB8
{
 public static void main(String args[]) throws IOException
 {
  char c = 219;
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  System.out.print("RECTANGLE\n  Enter Width : ");
  int w = Integer.parseInt(br.readLine());
  System.out.print("  Enter Length : ");
  int l = Integer.parseInt(br.readLine());
  System.out.println("");
  for(int i = 1;i <= w;i++)
  {
   for(int j = 1;j <= l;j++)
   {
    System.out.print(c);
   }
   System.out.println("");
  }
 }
}

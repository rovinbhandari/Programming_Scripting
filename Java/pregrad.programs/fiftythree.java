/*                                 PATTERN                                  */

import java.io.*;
class fiftythree
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.print("Enter a value from 1 to 26 : "); 
  int n = Integer.parseInt(x.readLine());
  char e;
  for(int i=(n-1);i>=0;i--)
  {
   e='A';
   for(int j=(n-i-1);j>0;j--)
   {
    System.out.print(" ");
   }
   for(int k=0;k<=i;k++)
   {
    System.out.print(e+" ");
    e++;
   }
   System.out.println();
  }
  System.out.println();
 }
}

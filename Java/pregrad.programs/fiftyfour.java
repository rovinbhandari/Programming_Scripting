/*                                 PATTERN                                  */

import java.io.*;
class fiftyfour
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.print("Enter a value from 1 to 26 : "); 
  int n=Integer.parseInt(x.readLine());
  char e;
  for(int i=0;i<n;i++)
  {
   e = 'A';
   for(int j=(n-i-1);j>=0;j--)
   {
    System.out.print(" ");
   }
   for(int k=0;k<=(i+1);k++)
   {
    System.out.print((char)(e+k));
    
   }

   for(int l=i;l>=0;l--)
   {
    System.out.print((char)(e+l));
   }
   System.out.println();
  }
  System.out.println();
 }
}

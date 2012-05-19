import java.io.*;
class sixteen
{
 public static void main(String args[]) throws IOException
 {
  InputStreamReader a = new InputStreamReader(System.in);
  BufferedReader x=new BufferedReader(a);
  System.out.println("Enter number of characters to be printed :");
  int b = Integer.parseInt(x.readLine());
  for(char c=0; c<=b; c++)
  {
   int q=c;
   System.out.print(" "+q+"="+c+);
  }
 }
}


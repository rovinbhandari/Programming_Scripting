/*          PROGRAM TO CALCULATE THE PALINDROME OF A GIVEN NUMBER           */
import java.io.*;
class fiftynine
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
  long a,b,c,d,e,f;
  f = 0l;
  System.out.println("");
  System.out.print("Enter the number to calculate its palindrome : \n  ==> ");
  a=Long.parseLong(x.readLine());
  e=a;
  System.out.println("");
  for(long i=0l; ;i++)
  {
   b=0;
   c=a;
   while(c != 0l)
   {
    f++;
    d = c%10l;
    b=b*10+d;
    c=c/10l;
   }
   if(a==b)
   { 
    System.out.println("Palindrome of " + e + " = " + b);
    System.out.println("");
    System.out.println("No.of iterations = " + i + " * " + f + " = " + i * f);
    return;
   }
   else
   {
    a=a+b;
   }
  }
 }
}

/*             PROGRAM TO FIND THE PRIME FACTORS OF AN INTEGER              */
import java.io.*;
class fortyseven
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("-----------------PROGRAM TO FIND THE PRIME FACTORS OF AN INTEGER----------------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter an integer :");
  System.out.print("==> ");
  long a1 = Long.parseLong(x.readLine());
  long a = 2;
  System.out.println("");
  if((a1 > 0) && (a1 != 1))
  {
   System.out.println("PRIME FACTORS OF " + a1 + " :");
   System.out.println("");
   System.out.print("  1");  
   while(a1 > 1)
   {
    if(a1 % a == 0)
    {
     System.out.print("  x  " + a);
     a1 = a1 / a;
    }
    else
    {
     a++;
    }
   }
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
   System.out.println("");
  }
  else if(a1 == 0)
  {
   System.out.println("ZERO does not have any prime factors.");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
   System.out.println("");
  }
  else if(a1 == 1)
  {
   System.out.println("PRIME FACTORS OF 1 :");
   System.out.println("  1  x  1");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
   System.out.println("");
  }
  else
  {
   System.out.println("Wrong entry...!");
   System.out.println("Please do not enter a negative value.");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
   System.out.println("");
  }
 }
}

/*                    PROGRAM TO ADD INDEFINITE NUMBERS                     */
import java.io.*;
class fortynine
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("");
  System.out.println("  >>>>>>>>>>>>>>>>>>>PROGRAM TO ADD INDEFINITE NUMBERS<<<<<<<<<<<<<<<<<<<  ");
  System.out.println("");
  System.out.println("Choose the type of numbers to add :");
  System.out.println("# 1 # Integers");
  System.out.println("# 2 # Floating point numbers");
  System.out.print("  ==>  ");
  int a1 = Integer.parseInt(x.readLine());
  long a2;
  double a3;
  String a4,a5;
  long sum1 = 0l;
  double sum2 = 0.0d;
  switch(a1)
  {
   case 1 :
            for(long i = 1l; ;i++)
            {
             System.out.println("");
             System.out.print("Enter number (<v> to end) : ");
             a4 = x.readLine();
             a4 = a4.trim();
             if(a4.equalsIgnoreCase("v"))
             {
              System.out.println("");
              System.out.println("Sum of Integers = " + sum1);
              System.out.println("");
              System.out.println("   _____________________________________________________________________   ");
              System.out.println("");
              return;
             }
             else
             {
              a2 = Long.parseLong(a4);
              sum1 += a2;
             }
            }
   case 2 :
            for(long i = 1l; ;i++)
            {
             System.out.println("");
             System.out.print("Enter number (<v> to end) : ");
             a5 = x.readLine();
             a5 = a5.trim();
             if(a5.equalsIgnoreCase("v"))
             {
              System.out.println("");
              System.out.println("Sum of Numbers = " + sum2);
              System.out.println("");
              System.out.println("   _____________________________________________________________________   ");
              System.out.println("");
              return;
             }
             else
             {
              a3 = Double.parseDouble(a5);
              sum2 += a3;
             }
            }
   default :
             System.out.println("");
             System.out.println("Wrong Entry !");
             System.out.println("");
             System.out.println("   _____________________________________________________________________   ");
             System.out.println("");
  }
 }
}

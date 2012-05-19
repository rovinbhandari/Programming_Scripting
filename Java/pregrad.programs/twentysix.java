/*   PROGRAM TO FIND THE LARGEST TWO OUT OF INDEFINITE NUMBER OF NUMBERS    */
import java.io.*;
class twentysix
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("------PROGRAM TO FIND THE LARGEST TWO OUT OF INDEFINITE NUMBER OF NUMBERS-------");
  System.out.println("");
  double a,b,e;
  a = 0.0;
  b = 0.0;
  for(int i = 1 ; ; i++)
  {
   System.out.println("Enter The Number : ");
   System.out.println("                                   (Enter < v > to stop) : ");
   System.out.print("==> ");
   String c = x.readLine();
   System.out.println("");
   if(c.equalsIgnoreCase("v"))
   {
    System.out.println("--------------------------------------------------------------------------------");
    break;
   }
   else
   {
    double d = Double.parseDouble(c);
    if(d >= a)
    {
     if(d > a)
     {
      b = a;
     }
     a = d;
    }
    else              
    {                
     if(d > b)
     {
      b = d;
     }
    }
   }
  }
  System.out.println("");
  System.out.println("The largest number is : " + a);
  System.out.println("The second largest number is : " + b);
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
  System.out.println("");
 }
}

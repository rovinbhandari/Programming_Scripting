/*     PROGRAM TO FIND THE LARGEST OUT OF INDEFINITE NUMBER OF NUMBERS      */
import java.io.*;
class twentyfour
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("--------PROGRAM TO FIND THE LARGEST OUT OF INDEFINITE NUMBER OF NUMBERS---------");
  System.out.println("");
  double a,b;
  a = 0.0;
  b = 0.0;
  for(int i = 1 ; ; i++)
  {
   System.out.println("Enter The Number : ");
   System.out.println("                                   (Enter < v > to stop)   ");
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
    b = Double.parseDouble(c);
    if(b > a)
    {
     a = b; 
    }
   }
  }
  System.out.println("");
  System.out.println("The largest number is : " + a);
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
 }
}

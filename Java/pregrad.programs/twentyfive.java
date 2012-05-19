/*         PROGRAM TO FIND THE MIDDLE ELEMENT OUT OF THREE NUMBERS          */
import java.io.*;
class twentyfive
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("---------PROGRAM TO FIND THE MIDDLE ELEMENT OUT OF THREE NUMBERS---------");
  System.out.println("Enter Three Numbers :");
  System.out.print("1st no.: ");
  double a = Double.parseDouble(x.readLine());
  System.out.print("2nd no.: ");
  double b = Double.parseDouble(x.readLine());
  System.out.print("3rd no.: ");
  double c = Double.parseDouble(x.readLine());
  if((a > b && a < c) || (a > c && a < b))
  {
   System.out.println("The first number is the middle element. : " + a);
  }
  else if((b > a && b < c) || (b > c && b < a))
  {
   System.out.println("The second number is the middle element. : " + b);
  }
  else if((c > a && c < b) || (c < a && c > b))
  {
   System.out.println("The third number is the middle element. : " + c);
  }
  else
  {
   System.out.println("Any of the elements is equal to the other.");
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
 }
}

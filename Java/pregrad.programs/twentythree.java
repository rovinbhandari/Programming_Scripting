/*             PROGRAM TO FIND THE LARGEST OUT OF THREE NUMBERS             */
import java.io.*;
class twentythree
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("------------PROGRAM TO FIND THE LARGEST OUT OF THREE NUMBERS------------");
  System.out.println("Enter Three Numbers :");
  System.out.print("1st no.: ");
  double a = Double.parseDouble(x.readLine());
  System.out.print("2nd no.: ");
  double b = Double.parseDouble(x.readLine());
  System.out.print("3rd no.: ");
  double c = Double.parseDouble(x.readLine());
  if(a > b && a > c)
  {
   System.out.println("The first number is the largest. : " + a);
  }
  else if(b > a && b > c)
  {
   System.out.println("The second number is the largest. : " + b);
  }
  else
  {
   System.out.println("The third number is the largest. : " + c);
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
 }
}

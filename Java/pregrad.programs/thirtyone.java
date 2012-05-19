/*          PROGRAM TO PRINT TIMES X TABLES OF ANY NUMBER ENTERED           */
import java.io.*;
class thirtyone
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("----------------------------------TIMES X TABLES--------------------------------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the number :");
  double a = Double.parseDouble(x.readLine());
  for(int i = 1;i <= 20;i++)
  {
   System.out.println("   " + a + " x " + i + " = " + (a * i));
  }
  System.out.println("--------------------------------------------------------------------------------");
 }
}

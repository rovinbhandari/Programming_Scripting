/*                   PROGRAM TO PRINT THE FIBONACCI SERIES                  */
import java.io.*;
class thirty
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("-------------------------------FIBONACCI SERIES---------------------------------");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter the number greater than or equal to the last number of the ");
  System.out.println("required series :");
  double d = Double.parseDouble(x.readLine());
  System.out.println("");
  long a = 0;
  long b = 1;
  long c = 0;
  System.out.print(a + "  " + b + "  ");
  for(int i = 1; ;i++)
  {
   c = a + b;
   a = b;
   b = c;
   if(c > d)
   {
    break;
   }
   if(c < 0)
   {
    break;
   }
   System.out.print(c + "  ");
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
  System.out.println("");
 }
}

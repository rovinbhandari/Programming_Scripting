/*         PROGRAM TO  SORT THE ELEMENTS OF AN ARRAY BY BUBBLE SORT         */
import java.io.*;
class thirtytwo
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("----------------------------------BUBBLE SORT-----------------------------------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the number of elements to be sorted :");
  int a = Integer.parseInt(x.readLine());
  System.out.println("");
  System.out.println("Enter the elements :");
  double z[] = new double[a];
  for(int i = 0;i < a;i++)
  {
   System.out.print("==> ");
   double b = Double.parseDouble(x.readLine());
   z[i] = b;
  }
  for(int i = 0;i < a;i++)
  {
   for(int j = 0;j < (a - 1);j++)
   {
    if(z[j] > z[j + 1])
    {
     double c = z[j];
     z[j] = z[j + 1];
     z[j + 1] = c;
    }
   }
  }
  System.out.println("");
  System.out.println("Ascending order of the elements entered :");
  for(int i = 0;i < a;i++)
  {
   System.out.print(z[i] + "  ");
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
  System.out.println("");
 }
}   

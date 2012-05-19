/*             PROGRAM TO MULTIPLY/ADD THE ELEMENTS OF AN ARRAY             */
import java.io.*;
class thirtysix
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("--------------MULTIPLICATION/ADDITION OF ELEMENTS OF AN ARRAY-----------------");
  System.out.println("");
  System.out.println("Choose from :");
  System.out.println("# 1 # ADDITION");
  System.out.println("# 2 # MULTIPLICATION");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  int q = Integer.parseInt(x.readLine());
  if((q != 1) && (q != 2))
  {
   System.out.println("");
   System.out.println("Wrong entry...!");
   System.out.println("");
   System.out.println("------------------------------------------------------------------------------");
   return;
  }
  else
  {
   System.out.println("Enter the number of elements :");
   int w = Integer.parseInt(x.readLine());
   double z[] = new double[w];
   System.out.println("Enter the elements :");
   for(int i = 0 ; i < w ; i++)
   {
    System.out.print("==> ");
    double e = Double.parseDouble(x.readLine());
    z[i] = e;
   }  
   System.out.println("");
   double sum = 0.0;
   double pro = 1.0;
   if(q == 1)
   {
    for(int j = 0 ; j < w ; j++)
    {
     sum = sum + z[j];
    }
    System.out.println("Sum of the elements : ");
    System.out.println(sum);
   }
   else
   {
    for(int k = 0 ; k < w ; k++)
    {
     pro = pro * z[k];
    }
    System.out.println("Product of the elements :");
    System.out.println(pro);
   }
   System.out.println("");
   System.out.println("------------------------------------------------------------------------------");
  }
 } 
}

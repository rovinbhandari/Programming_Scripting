/*    PROGRAM TO ADD/SUBTRACT/MULTIPLY/DIVIDE THE ELEMENTS OF TWO ARRAYS    */
import java.io.*;
class thirtyseven
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("----MULTIPLICATION/ADDITION/DIVISION/SUBTRACTION OF ELEMENTS OF TWO ARRAYS----");
  System.out.println("");
  System.out.println("Choose from :");
  System.out.println("# 1 # ADDITION");
  System.out.println("# 2 # MULTIPLICATION");
  System.out.println("# 3 # SUBTRACTION");
  System.out.println("# 4 # DIVISION");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  int q = Integer.parseInt(x.readLine());
  if((q != 1) && (q != 2) && (q != 3) && (q != 4))
  {
   System.out.println("");
   System.out.println("Wrong Entry ...!");
   System.out.println("");
   System.out.println("------------------------------------------------------------------------------");
   return;
  }
  else
  {
   System.out.println("Enter the number of elements to be entered in each array :");
   int w = Integer.parseInt(x.readLine());
   double z[] = new double[w];
   double v[] = new double[w];
   System.out.println("Enter the elements of the first array :");
   for(int i = 0 ; i < w ; i++)
   {
    System.out.print("==> ");
    double e = Double.parseDouble(x.readLine());
    z[i] = e;
   }
   System.out.println("Enter the elements of the second array :");
   for(int l = 0 ; l < w ; l++)
   {
    System.out.print("==> ");
    double f = Double.parseDouble(x.readLine());
    v[l] = f;
   }
   System.out.println("");
   double sum[] = new double[w];
   double pro[] = new double[w];
   double sub[] = new double[w];
   double div[] = new double[w];
   if(q == 1)
   {
    for(int j = 0 ; j < w ; j++)
    {
     sum[j] = z[j] + v[j];
    }
    System.out.println("Sum of the corresponding elements of the arrays : ");
    for(int r = 0 ; r < w ; r++)
    {
     System.out.println(sum[r]);
    }
   }
   else if(q == 2)
   {
    for(int k = 0 ; k < w ; k++)
    {
     pro[k] = z[k] * v[k];
    }
    System.out.println("Product of the corresponding elements of the arrays :");
    for(int t = 0 ; t < w ; t++)
    {
     System.out.println(pro[t]);
    }
   }
   else if(q == 3)
   {
    for(int m = 0 ; m < w ; m++)
    {
     sub[m] = z[m] - v[m];
    }
    System.out.println("Difference of the corresponding elements of the arrays :");
    for(int y = 0 ; y < w ; y++)
    {
     System.out.println(sub[y]);
    }
   }
   else
   {
    for(int n = 0 ; n < w ; n++)
    {
     div[n] = z[n] / v[n];
    }
    System.out.println("Quotient of the corresponding elements of the arrays :");
    for(int u = 0 ; u < w ; u++)
    {
     System.out.println(div[u]);
    }
   }
   System.out.println("");
   System.out.println("------------------------------------------------------------------------------");
  } 
 }  
}

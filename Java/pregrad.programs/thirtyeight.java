/*        PROGRAM TO SORT THE ELEMENTS OF AN ARRAY BY SELECTION SORT        */
import java.io.*;
class thirtyeight
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("---------------------------------SELECTION SORT---------------------------------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the number of elements to be sorted :");
  int q = Integer.parseInt(x.readLine());
  double z[] = new double[q];
  System.out.println("");
  System.out.println("Enter the elements :");
  for(int i = 0 ; i < q ; i++)
  {
   System.out.print("==> ");
   double w = Double.parseDouble(x.readLine());
   z[i] = w;
  }
  double e;
  double r;
  double t;
  int m,n,y;
  y = 0;
  for(m = 0 ; m < q ; m++)
  {
   r = t = 0.0;
   e = z[m];
   for(n = (m + 1) ; n <= q ; n++)
   {
    if(z[n] <= e)
    {
     t = z[n];
     y++;
    }
    else
    {
     r = e;
    }
   }
   if(y == 0.0)
   {
    z[m] = r;
   }
   else
   {
    z[m] = t;
   }
   z[n] = e;
  }
  System.out.println("");
  System.out.println("Elements sorted in Ascending Order are :");
  for(int l = 0 ; l < q ; l++)
  {
   System.out.println("   " + z[l]);
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
  System.out.println("");
 }
}

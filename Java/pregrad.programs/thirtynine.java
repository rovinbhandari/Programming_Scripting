/*       PROGRAM TO SORT THE ELEMENTS OF AN ARRAY BY INSERTION SORT         */
import java.io.*;
class thirtynine
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("---------------------------------INSERTION SORT---------------------------------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the number of elements to be sorted :");
  int q = Integer.parseInt(x.readLine());
  double z[] = new double[q + 1];
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
  int m,n;
  for(int j = 0 ; j < (q - 1) ; j++) 
  {
   m = j;
   n = m + 1;
   while((m >= 0) && (z[n] < z[m]))
   {
    m--;
   }
   if(m != j)
   {
    e = z[n];
    while(n > (m + 1))
    {
     z[n] = z[n - 1];
     n--;
    }
    z[m + 1] = e;
   }
  }
  System.out.println("");
  System.out.println("Elements sorted in Ascending Order are :");
  for(int a1 = 0 ; a1 < q ; a1++)
  {
   System.out.println("  " + z[a1]);
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
  System.out.println("");
 }
}
    

/*      PROGRAM TO SEARCH AN ELEMENT IN AN ARRAY USING 'BINARY SEARCH'      */
import java.io.*;
class thirtyfive
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("---------------------------------BINARY SEARCH----------------------------------");
  System.out.println("");
  int z[] = {-128,-111,-56,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,5,5,5,6,7,7,8,8,9,10,12,13,14,16,18,19,27,30,56,76,84,87,90,99,100,111,158,455,767,878,911,912,999,1000,1991,1996};
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter an integer to find :");
  int a = Integer.parseInt(x.readLine());
  int f = z.length - 1;
  int r = 0;
  int p;
  for(int c = 0;c < z.length;c++)
  {
   p = (r + f) / 2;
   if(a == z[p])
   {
    System.out.println("Element " + a + " found at position : " + (p + 1) + " in the array.");
    System.out.println("");
    System.out.println("--------------------------------------------------------------------------------");
    return;
   }
   else if(a > z[p])
   {
    r = p;
   }
   else if(a < z[p])
   {
    f = p;
   }
  }
  System.out.println("");
  System.out.println("Element " + a + " not found in the array.");
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
 }
}
                                                            

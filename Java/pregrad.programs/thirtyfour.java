/*      PROGRAM TO SEARCH AN ELEMENT IN AN ARRAY USING 'LINEAR SEARCH'      */
import java.io.*;
class thirtyfour
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("---------------------------------LINEAR SEARCH----------------------------------");
  System.out.println("");
  int z[] = {-12,-28,23,-87,-356,62,67,256,8,90,1,145,57,78,980,3,32,5,6,78,78,74,8,78,798,56,5,74,356,57655556,3333336,676,123,456,789,0,1,6,2,12,5241,23,4,456,64,46,78,87926,76,54,67,1,23,3,2,1,3,4,556,5667,78,909854,3,1,42,235,4,5,6,8,0,3,4,5,36,767,6767,657,87684,24525,4353,556,767,78,78,25,345,56,7,78,89,89,97,9,0,5,21,84,5247798,7,32,5,7,8752,2,5,677889,56732,4432567,89874,32,22,544567,78,89743,232,58,5,345,78,78,9,2,4,5,768,9,4,2,1,4,5254,912,536,27,6,4,1991,91,911};
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter an integer to find :");
  int a = Integer.parseInt(x.readLine());
  for(int i = 0;i < z.length;i++)
  {
   if(z[i] == a)
   {
    System.out.println("");
    System.out.println("Element " + a + " found at : " + "position " + (i + 1) + " in the array.");
    System.out.println("");
    System.out.println("--------------------------------------------------------------------------------");
    return;
   }
  }
  System.out.println("");
  System.out.println("Element " + a + " not found in the array.");
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
 }
}

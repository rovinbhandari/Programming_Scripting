/*     PROGRAM TO FIND THE SQUARE ROOT OF A NUMBER BY BISECTION METHOD      */
import java.io.*;
class fortysix
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("---------PROGRAM TO FIND THE SQUARE ROOT OF A NUMBER BY BISECTION METHOD--------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter a number :");
  System.out.print("==> ");
  double a1 = Double.parseDouble(x.readLine());
  double a2 = a1;
  String a3 = Double.toString(a2);
  int a4 = a3.indexOf('.');
  String a5 = a3.substring(0,a4);
  int a6 = Integer.parseInt(a5);
  int a,b;
  a = a6;
  if((a1 != 1.0) && (a1 > 0.0))
  {
   while((a * a) > a1)
   {
    a--;
   }
   b = a + 1;
   double u,l,m;
   l = (double)a;
   u = (double)b;
   while((u - l) > 0.001)
   {
    m = (u + l)/2;
    if((m * m) == a1)
    {
     String d0 = Double.toString(m);
     int d00 = d0.indexOf('e');
     int d000 = d0.indexOf('E');
     if((d00 == -1) || (d000 == -1))
     {
      double d1 = m;
      double d2,d6,d7;
      int d4;
      d1 = d1 + 0.0005;
      d2 = d1 * 1000.0;
      String d3 = Double.toString(d2);
      d4 = d3.indexOf('.');
      String d5 = d3.substring(0,d4);
      d6 = Double.parseDouble(d5);
      d7 = d6 / 1000.0;
      m = d7;
      System.out.println("");
      System.out.println("Square root of " + a1 + " correct to three places of decimal :");
      System.out.println(" <  " + m + "  > ");
      System.out.println("");
      System.out.println("--------------------------------------------------------------------------------");
     }
     else
     {
      System.out.println("");
      System.out.println("Square root of " + a1 + " :");
      System.out.println(" <  " + m + "  > ");
      System.out.println("");
      System.out.println("--------------------------------------------------------------------------------");
     }
    }
    else if((m * m) > a1)
    {
     u = m;
    }
    else if((m * m) < a1)
    {
     l = m;
    }
   }
   m = (u + l) / 2;
   String c0 = Double.toString(m);
   int c00 = c0.indexOf('e');
   int c000 = c0.indexOf('E');
   if((c00 == -1) || (c000 == -1))
   {
    double c1 = m;
    double c2,c6,c7;
    int c4;
    c1 = c1 + 0.0005;
    c2 = c1 * 1000.0;
    String c3 = Double.toString(c2);
    c4 = c3.indexOf('.');
    String c5 = c3.substring(0,c4);
    c6 = Double.parseDouble(c5);
    c7 = c6 / 1000.0;
    m = c7;
    System.out.println("");
    System.out.println("Square root of " + a1 + " correct to three places of decimal :");
    System.out.println(" <  " + m + "  > ");
    System.out.println("");
    System.out.println("--------------------------------------------------------------------------------");
   } 
   else
   {
    System.out.println("");
    System.out.println("Square root of " + a1 + " :");
    System.out.println(" <  " + m + "  > ");
    System.out.println("");
    System.out.println("--------------------------------------------------------------------------------");
   }
  }
  else if(a1 == 0)
  {
   System.out.println("");
   System.out.println("Square root of ZERO :");
   System.out.println(" <  0.0  > ");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
  }
  else if(a1 == 1)
  {
   System.out.println("");
   System.out.println("Square root of ONE :");
   System.out.println(" <  1.0  > ");
   System.out.println("");
   System.out.println("--------------------------------------------------------------------------------");
  }
  else if(a1 < 0)
  {
   System.out.println("");
   System.out.println("Wrong entry...!");
   System.out.println("Please do not enter a negative value.");
   System.out.println("--------------------------------------------------------------------------------");
  }
  else
  {
   System.out.println("");
   System.out.println("Wrong entry...!");
   System.out.println("--------------------------------------------------------------------------------");
  }
 }
}
   





   

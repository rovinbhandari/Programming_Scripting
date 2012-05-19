/*                 PROGRAM TO CALCULATE THE AREA OF A TRIANGLE              */
import java.io.*;
import java.lang.Math;
class fourteen
{
 public static void main(String args[]) throws IOException
 {
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader x = new BufferedReader(isr);
  System.out.println(" ");
  System.out.println(" ");
  System.out.println("<<<<<<<<<<<<<<<<<<<PROGRAM TO CALCULATE THE AREA OF A TRIANGLE>>>>>>>>>>>>>>>>>>");
  System.out.println("********************************************************************************");
  System.out.println("1. CALCULATE USING : 1/2(BASE x HEIGHT) ");
  System.out.println("~~~~~~~~~~~~~~~~~~ OR ~~~~~~~~~~~~~~~~~~");
  System.out.println("2. CALCULATE USING : HERO'S FORMULA ");
  System.out.println(" ");
  System.out.println("ENTER YOUR CHOICE : ");
  int a = Integer.parseInt(x.readLine());
  System.out.println(" ");
  if(a==1)
  {
   System.out.println("ENTER THE LENGTH OF THE BASE OF THE TRIANGLE : ");
   float b = Float.parseFloat(x.readLine());
   System.out.println(" ");
   System.out.println("ENTER THE LENGTH OF THE HEIGHT OF THE TRIANGLE : ");
   float h = Float.parseFloat(x.readLine());
   float area = (b*h)/2.0f;
   System.out.println(" ");
   System.out.println("THE AREA OF THE TRIANGLE IS : "+area+" square unit.");
  }
  else if(a==2)
  {
   System.out.println("ENTER THE LENGTH OF THE FIRST SIDE OF THE TRIANGLE : ");
   float p = Float.parseFloat(x.readLine());
   System.out.println(" ");
   System.out.println("ENTER THE LENGTH OF THE SECOND SIDE OF THE TRIANGLE : ");
   float q = Float.parseFloat(x.readLine());
   System.out.println(" ");
   System.out.println("ENTER THE LENGTH OF THE THIRD SIDE OF THE TRIANGLE : ");
   float r = Float.parseFloat(x.readLine());
   if(p+q>r && q+r>p && r+p>q)
   {
    float s = (p+q+r)/2.0f;
    float ar = s*((s-p)*(s-q)*(s-r));
    double area1;
    area1 = Math.sqrt(ar);
    System.out.println(" ");
    System.out.println("THE AREA OF THE TRIANGLE IS : "+area1+" square unit.");
   }
   else
   {
   System.out.println(" ");
   System.out.println("THE VALUES HAVE NOT BEEN ENTERED CORRECTLY");  
   }
  }
  else
  {
   System.out.println(" ");
   System.out.println("THE CHOICE HAS NOT BEEN ENTERED CORRECTLY");
  }
  System.out.println(" ");
  System.out.println("--------------------------------------------------------------------------------");
 }
}

/*Program to calculate the diameter,volume and surface area of a sphere having
  radius as 77cm. by parameter passing through functions
*/
class four
{
 void display(int r)
 {
  float d=2*r;
  float vol=(r*r*r*22*4)/(7*3);
  float sa=(4*22*r*r)/7;
  System.out.println("====================================================");
  System.out.println("Radius of the sphere = "+r);
  System.out.println("Diameter of the sphere = "+d);
  System.out.println("Volume of the sphere = "+vol);
  System.out.println("Total surface area of the sphere = "+sa);
  System.out.println("====================================================");
 }
}
class four1
{
 public static void main(String args[])
 {
  four f1=new four();
  f1.display(77);
 }
}




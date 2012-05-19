class twentyseven
{
 public static void main(String args[])
 {
  double a = 247.583;
  double b = 247.483;
  a+=0.5;
  b+=0.5;
  String s1;
  s1 = Double.toString(a);
  int i = s1.indexOf('.');
  String s2 = s1.substring(0,i);
  String s3;
  s3 = Double.toString(b);
  int j = s3.indexOf('.');
  String s4 = s3.substring(0,j);
  System.out.println("a="+a);
  System.out.println("b="+b);
  System.out.println("a1="+s2);
  System.out.println("b1="+s4);
 }
}


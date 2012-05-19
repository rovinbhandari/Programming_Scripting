class temp14
{
 public static void main(String args[])
 {
  String a="I have a computer.It's fun";
  String b="";
  int d=a.lastIndexOf(' ');
  b=a.substring(d);
  int c=a.length();
  System.out.println("a= "+a);
  System.out.println("b= "+b);
  System.out.println("c= "+c);
  System.out.println("d= "+d);
  a=a.substring(0,21);
  System.out.println("a= "+a);
 }
}

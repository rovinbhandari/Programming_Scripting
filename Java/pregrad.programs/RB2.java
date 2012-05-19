//constructors
class RB2
{
 public int i,j;
 RB2(int a,int b)
 {
  i = a;
  j = b;
 }
 private void print()
 {
  System.out.println("i = " + i + " and j = " + j);
 }
 public void f()
 {
  RB2 a1 = new RB2(2,5);
  a1.print();
  new RB2(4,10).print();
 }
}
class RB
{
 public static void main(String args[])
 {
  RB2 a2 = new RB2(8,20);
  a2.f();
 // a2.print(); // wont run coz print is private
 }
}
                                                

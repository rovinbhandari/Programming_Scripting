class j2t1
{
 public static void main(String args[])
 {
  {
   int x,y;
   y=6;
   x = ++y + 2 * y;
   System.out.println();
   System.out.println(" # 1 #   x = " + x + "   &   y = " + y);
  }
  {
   int x=10;
   x += --x + x++ + ++x;
   System.out.println(" # 2 #   x = " + x);
  } 
  {
   int a=5;
   a -= a++ + --a + ++a * 2; 
   System.out.println(" # 3 #   a = " + a);
  }
  {
   System.out.println(" # 4 #   ^^^^   ");
  }
  {
   int a,x,y,z;
   x=0;
   y=9;
   z=10;
   a = +z + ++y/z;
   System.out.println(" # 5 #   x = " + x + "   &   y = " + y);
   System.out.println("         z= " +z + "  &  a= " +a);
  }
  {
   int a,y;
   a=10;
   y = --a + ++a + --a * 7;
   System.out.println(" # 6 #  y = " + y);
  }
  {
   int y=3;
   y *= y++ + --y * 5 + y-- + ++y - 2;
   System.out.println(" # 7 #  y = " + y);
  }
 }
}



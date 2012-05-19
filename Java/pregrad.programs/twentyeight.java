//   ARRAYS
class twentyeight
{
 public static void main(String args[])
 {
  int x[] = new int[10];
  for(int i = 0; i < x.length; i++)
  {
   x[i] = (i + 4)*i;
  }
  for(int j = 0; j < x.length; j++)
  {
   System.out.println("Element " + (j + 1) + " = " + x[j]);
  }
 }
}


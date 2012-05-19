class test
{
 public static void main(String args[])
 {
  int [] a = new int[12];
  for(int k = 0; k < 12; k++)
  {
   a[k] = 1;
  }
  a[10] = 20;
  System.out.print("ORIGINAL MATRIX : ");
  for(int k = 0; k < 12; k++)
  {
   System.out.print(a[k] + " ");
  }
  int i = 10;
  a[i] = i++;
  System.out.print("NEW MATRIX : ");
  for(int k = 0; k < 12; k++)
  {
   System.out.print(a[k] + " ");
  }
 }
}

import java.io.*;
class RB25
{
 public int a,b,n,f;
 public String s;
 public char c[];
 public int x[];
 RB25(String s1)
 {
  s = s1;
  n = s.length();
  c = new char[n];
  x = new int[n];
 }
 void chararray()
 {
  for(int i = 0;i < n;i++)
  {
   c[i] = s.charAt(i);
  }
 }
 boolean intarraycheck()
 {
  for(int i = 0;i < n - 1;i++)
  {
   for(int j = n - 1;j > i;j--)
   {
    a = x[i];
    b = x[j];
    if(a == b)
    {
     return (false);
    }
   }
  }
  return (true);
 }
 void intarray(int d)
 {
  if(x[d] < n - 1)
  {
   x[d]++;
  }
  else
  {
   x[d] = 0;
   if(d < n - 1)
   {
    intarray(++d);
   }
  }
 }
 int factorial(int e)
 {
  f = 1;
  for(int i = e;i >= 1;i--)
  {
   f *= i;
  }
  return (f);
 }
 void printword()
 {
  for(int i = 0;i < n;i++)
  {
   System.out.print(c[x[i]]);
  } 
  System.out.print('\t');
 }
}
class RB25a
{
 public static void main(String args[]) throws IOException
 {
  int z = 1;
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  System.out.print("Enter a String\n   ===> ");
  RB25 r = new RB25(br.readLine());
  r.chararray();
  System.out.println("Permutaions of the characters of the string are :");
  while(z <= r.factorial(r.n))
  {
   do
   {
    r.intarray(0);
   }
   while(!(r.intarraycheck()));
   r.printword(); // Q/. How to access c[] & x[] here (like n is accessed via r.n) ?
   z++;
  }
 }
}

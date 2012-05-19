import java.io.*;
import java.lang.Math.*;
class RB26
{
 String s,t1,t2;
 long n,a;
 int l;
 int x[];
 int y1[] = {20,30,40,50,60,70,80,90};
 int y2[] = {10,11,12,13,14,15,16,17,18,19};
 int y3[] = {1,2,3,4,5,6,7,8,9};
 String z1[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
 String z2[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
 String z3[] = {"one","two","three","four","five","six","seven","eight","nine"};
 RB26(String s1)
 {
  s = s1;
  l = s.length();
 }
 void check()
 {
  if(s.indexOf(" ") == -1)
  {
   n2w();
  }
/*  else
  {
   w2n();
  } */
 }
 void n2w()
 {
  n = Long.parseLong(s);
  long a = n;
  x = new int[6];
  for(int i = 0;i < 3;i++)
  {
   long c = (long) Math.pow(10.0d,(double) (7 - 2 * i));
   x[i] = (int) (a / c);
   a %= c;
  }
  for(int i = 3;i < 6;i++)
  {
   long c = (long) Math.pow(10.0d,(double) (5 - i));
   x[i] = (int) (a / c);
   a %= c;
  }
  String s1,s2;
  s1 = s2 = "";
  System.out.println("Number :" + n + " in words is :");
  for(int i = 0;i < 3;i++)
  {
   if(x[i] != 0)
   {
    s1 = TOSTRING(x[i]);
    switch(i)
    {
     case 0 : s2 = "crore";
     break;
     case 1 : s2 = "lakh";
     break;
     case 2 : s2 = "thousand";
    }
    System.out.print(s1 + " " + s2 + " ");
   }
  }
  if(n / 100l != 0)
  {
   long q1 = n % 1000l;
   q1 /= 100l;
   System.out.print(TOSTRING((int) (q1)) + " hundred ");
  }
  int q5 = (int) (n % 100l);
  System.out.print(TOSTRING(q5));
 }
 String TOSTRING(int q2)
 {
  String s3,s4;
  s3 = s4 = "";
  int q3 = q2  / 10 * 10;
  if(q3 != 0 && q3 != 10)
  {
   for(int i = 0;i < y1.length;i++)
   {
    if(y1[i] == q3)
    {
     s3 = z1[i];
    }
   }
   for(int i = 0;i < y3.length;i++)
   {
    if(y3[i] == (q2 % 10))
    {
     s4 = z3[i];
     break;
    }
   }
  }
  else if(q3 == 10)
  {
   for(int i = 0;i < y2.length;i++)
   {
    if(y2[i] == q2)
    {
     s3 = z2[i];
     break;
    }
   }
  }
  else
  {
   for(int i = 0;i < y3.length;i++)
   {
    if(y3[i] == q2)
    {
     s4 = z3[i];
     break;
    }
   }
  } 
  return (s3 + " " + s4);
 }
}







class RB26a
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  System.out.print("Enter a number in digits or words (upto 99crores)\n  ===> ");
  RB26 r = new RB26(br.readLine().trim());
  r.check();
 }
}

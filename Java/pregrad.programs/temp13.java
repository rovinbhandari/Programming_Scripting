import java.io.*;
class temp13
{
 String concatenate(String str,String str2)
 {
  String s=str.concat(str2);
  return s;
 }
 boolean check(String str)
 {
  if(str.endsWith("."))
  return true;
  else
  return false;
 }
}
class t13
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter a String :");
  String str=x.readLine();
  System.out.println("Choose one of these options :");
  System.out.println("# 1 # Concatenate two strings");
  System.out.println("# 2 # Check if the current string ends with a fullstop");
  int a=Integer.parseInt(x.readLine());
  temp13 t=new temp13();
  switch(a)
  {
   case 1 : System.out.println("Enter another string :");
            String str2=x.readLine();
            String e=t.concatenate(str,str2);
            System.out.println(e);
            break;
   case 2 : if(t.check(str))
            System.out.println("Yes");
            else
            System.out.println("No");
            break;
   default: System.out.println("Incorrect choice");
  }
 }
}

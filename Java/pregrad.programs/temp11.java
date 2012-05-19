import java.io.*;
class temp11
{
 float commission() throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter sales:");
  float a=Float.parseFloat(x.readLine());
  float com;
  if(a<5000)
  com=(5.0f/100.0f)*a;
  else if(a>=5000 && a<=10000)
  com=(8.0f/100.0f)*a;
  else
  com=(10.0f/100.0f)*a;
  return com;
 }
}
class t11
{
 public static void main(String args[]) throws IOException
 {
  temp11 t=new temp11();
  float c=t.commission();
  System.out.println(c);
 }
}

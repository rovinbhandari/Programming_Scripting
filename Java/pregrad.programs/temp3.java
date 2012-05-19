import java.io.*;
class Student
{
 int rollno;
 float eng,math,comp;
 String name;
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  Student s = new Student();
  System.out.println("Enter name :");
  s.name= x.readLine();
  System.out.println("Enter roll number :");
  s.rollno=Integer.parseInt(x.readLine());
  System.out.println("Enter english marks :");
  s.eng=Float.parseFloat(x.readLine());
  System.out.println("Enter maths marks :");
  s.math=Float.parseFloat(x.readLine());
  System.out.println("Enter computer marks :");
  s.comp=Float.parseFloat(x.readLine());
  float total = s.eng+s.math+s.comp;
  System.out.println("Enter maximum marks :");
  float mm = Float.parseFloat(x.readLine());
  float per=(total/mm)*100;
  System.out.println("Total = "+total + " out of "+mm);
  System.out.println("Percentage = " +per);
 }
}
 





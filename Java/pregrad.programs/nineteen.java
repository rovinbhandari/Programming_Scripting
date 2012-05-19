/*PROGRAM1 :
     Design a java class Student having the following features :
     (i).  name, roll number, class, marks, section
     (ii). design costructors having the following features :
           (a). there can be maximum 20 students in a section
           (b). there can be maximum 4 sections
     (iii).having facility to read and display information of the student
*/

class Student
{
 String name;
 int clas,marks;
 static byte section;
 static byte rollno;
 Student()
 {
  name = "";
  clas = 0;
  marks = 0;
  section = 0;
  rollno = 0;
 }
 Student(String n,int c,int m)
 {
  name = n;
  marks = m;
  clas = c;
  rollno++;
  if(rollno > 20)
  {
   int sec = (int)(rollno % 20);
   section = (byte)(sec);
   if(rollno > 40)
   {
    System.out.println("NO MORE ADMISSIONS");
   }
  }
  section++;
  System.out.println("NAME : " + n);
  System.out.println("MARKS : " + m);
  System.out.println("CLASS : " + c);
  System.out.println("ROLL NUMBER : " + rollno);
  System.out.println("SECTION : " + section);
 }
}
class student1
{
 public static void main(String args[])
 {
  Student s = new Student("Winty",5,95);
  Student s1 = new Student("Rainy",7,98);
 }
}
    


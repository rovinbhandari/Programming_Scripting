import java.io.*;
class p1
{
public static void main(String args[])throws IOException
{
BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
int t,r,g,b,w;
String s;
t=Integer.parseInt(in.readLine());
for(int i=0;i<t;i++)
{
s=in.readLine();
r=0;
g=0;
b=0;
w=0;
for(int j=0;j<s.length();j++)
{
if(s.charAt(j)=='R')
r++;
else if(s.charAt(j)=='G')
g++;
else if(s.charAt(j)=='B')
b++;
else if(s.charAt(j)=='W')
w++; 
}
if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
System.out.println("YES");
else 
System.out.println("NO");
}
}
}

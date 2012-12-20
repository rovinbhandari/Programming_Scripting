import java.io.*;



class Main
{
public static void main(String args[])throws IOException
{
int i,r,b,g,w,t;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
String s=new String();
t=Integer.parseInt(br.readLine());
while(t!=0)
{
    r=b=w=g=0;
s = br.readLine();
for(i=0;i<s.length();i++)
{
if(s.charAt(i)=='R')
r++;
if(s.charAt(i)=='B')
b++;
if(s.charAt(i)=='G')
g++;
if(s.charAt(i)=='W')
w++;    
}
if(r%2==0&&b%2==0&&g%2==0&&w%2==0)
{System.out.println("YES");}
else
{System.out.println("NO");}
t--;
}
}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*

* @author Sharvari
*/
public class A {

/*
* @param args the command line arguments
*/
public static void main(String[] args) throws IOException {
// TODO code application logic here
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
int colors[] = new int[4];
String s;

int t = Integer.parseInt(br.readLine());
for(int i=0;i<t;i++)
{ 
for(int k=0;k<4;k++)
{
colors[k]=0;
}
s= br.readLine();
int l= s.length();
for(int j=0;j<l; j++)
{
switch(s.charAt(j)) 
{
case 82: colors[0]++;
break;
case 71: colors[1]++;
break;
case 87: colors[2]++;
break;
case 66: colors[3]++;
break;
}
}// end for

int count=0;
if(colors[0]%2 ==0 && colors[1]%2 ==0 &&colors[2]%2 ==0 && colors[3]%2 ==0)
System.out.println("YES");
else 
System.out.println("NO");




}
}
}
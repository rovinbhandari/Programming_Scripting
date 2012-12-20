import java.util.*;
public class t1
{
public static void main(String[] args){
int T,count1=0,count2=0,count3=0,count4=0,i;
String[] st;
Scanner scan=new Scanner(System.in);
T=Integer.parseInt(scan.next());
if(T < 1 || T > 1000)
return;
st=new String[T];
for(int j=0;j<T;j++)
{
String str=scan.next();
int len=str.length();
if(len>50)
{
  st[j]="NO";
continue;
}
for( i=0;i<len;i++)
{

        if(str.charAt(i)=='R')
                count1++;
        else if(str.charAt(i)=='G')
                count2++;
        else if(str.charAt(i)=='W')
                count3++;
        else if(str.charAt(i)=='B')
                count4++;
        else
                break;
}
if(i == len)
{
if(count1%2==0 && count2%2==0 && count3%2==0 && count4%2==0)
                st[j]="YES";
else
		st[j]="NO";
}
else
                st[j]="NO";

count1=count2=count3=count4=0;
}
for(int j=0;j<T;j++)
{
System.out.println(st[j]);
}
}
}



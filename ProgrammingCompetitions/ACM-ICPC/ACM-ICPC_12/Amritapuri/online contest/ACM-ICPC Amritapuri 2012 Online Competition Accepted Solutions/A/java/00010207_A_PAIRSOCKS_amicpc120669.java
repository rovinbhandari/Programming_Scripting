import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class msocks
{
public static void main(String[]args)throws IOException
{
 int N=0,R=0,B=0,G=0,W=0;

BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
N=Integer.parseInt(br.readLine());
String arr[]=new String[N];
String check[]=new String[N];
for(int i=0;i<N;i++)
{
arr[i]=br.readLine();
}
for(int i=0;i<N;i++)
{
	R=G=B=W=0;
	for(int j=0;j<arr[i].length();j++)
	{
	if(arr[i].charAt(j)=='W')
		W++;
	if(arr[i].charAt(j)=='R')
		R++;
	if(arr[i].charAt(j)=='B')
		B++;
	if(arr[i].charAt(j)=='G')
		G++;
	}
if(R%2==0&&B%2==0&&G%2==0&&W%2==0)
{
check[i]="YES";
}
else
{
check[i]="NO";
}
}

for(int j=0;j<N;j++)
{
System.out.println(check[j]);
}
}
}
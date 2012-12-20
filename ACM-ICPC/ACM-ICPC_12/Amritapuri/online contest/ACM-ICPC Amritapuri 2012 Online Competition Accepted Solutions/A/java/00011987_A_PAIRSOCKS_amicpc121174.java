import java.io.*;
class PairSocks
{
public static void main(String args[]) throws Exception
{
	BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
	int n=Integer.parseInt(in.readLine());
	while(n>0&&n<=1000)
	{
		int r=0,g=0,w=0,b=0,i;
		String c=in.readLine();
		int l=c.length();
		for(i=0;i<l;i++)
		{
		    if(c.charAt(i)=='R')
			r++;
		    if(c.charAt(i)=='W')
			w++;
		    if(c.charAt(i)=='G')
			g++;	
		    if(c.charAt(i)=='B')
			b++;
		}
		if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
			System.out.println("YES");
		else
			System.out.println("NO");
		n--;
	}
}
}

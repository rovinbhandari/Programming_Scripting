import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(in.readLine());
		int n;
		int x;
		int min;
		int sum,i,temp;
		String a;
		int co[];
		char k;
		while(t>0)
		{
			a=in.readLine();
			co=new int[4];
			for(i=0;i<a.length();i++)
				{
				k=a.charAt(i);
				if(k=='R')
					co[0]++;
				else if(k=='G')
					co[1]++;
				else if(k=='B')
					co[2]++;
				else if(k=='W')
					co[3]++;
				}
			if(co[0]%2==0 && co[1]%2==0 && co[2]%2==0 && co[3]%2==0)
				System.out.println("YES");
			else
				System.out.println("NO");
			t--;
		}
	}
}
import java.io.*;
import java.util.*;
class A
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(System.in);
		int t;
		t=in.nextInt();
		while((t--)>0)
		{
			String a="";
			int r=0,b=0,g=0,w=0,flag=0;
			int len=0,i;
			a=in.next();
			len=a.length();
			for(i=0;i<len;i++)
			{
				switch(a.charAt(i))
				{
					case 'R':
						r++;
						break;
					case 'B':
						b++;
						break;
					case 'G':
						g++;
						break;
					case 'W':
						w++;
						break;
				}
			}
			if((r%2)==0)
			{
				if((b%2)==0)
				{
					if((g%2)==0)
					{
						if((w%2)==0)
						{
							flag=1;
						}
					}
				}
			}
			if(flag==1)
				System.out.println("YES");
			else
				System.out.println("NO");
			
		}
	}
}
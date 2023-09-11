import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class T1 {
	public static void main(String args[]) throws IOException
	{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		String c;
		int i,r,g,w,b,tc;
		tc=Integer.parseInt(br.readLine());
		for(;1<=tc&&tc<=1000;tc--)
		{
			c=br.readLine();
			r=0;b=0;w=0;g=0;
				for(i=0;i<c.length();i++)
				{
						if(c.charAt(i)=='R')
							r++;
						else if(c.charAt(i)=='G')
							g++;
						else if(c.charAt(i)=='B')
							b++;
						else if(c.charAt(i)=='W')
							w++;
				}
					
				if(r%2==0||r==0)
				{	
					if(g%2==0||g==0)
					{
						if(b%2==0||b==0)
						{
							if(w%2==0||w==0)
							{
								System.out.println("YES");
							}
							else
							{
								System.out.println("NO");
							}
						}
						else
						{
							System.out.println("NO");
						}
					}
					else
					{
						System.out.println("NO");
					}
				}
				else
				{
					System.out.println("NO");
				}
		}
	}
}
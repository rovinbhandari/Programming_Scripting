import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		BufferedReader c=new BufferedReader(new InputStreamReader(System.in));
		//Scanner c=new Scanner(System.in);
		int T=Integer.parseInt(c.readLine());
		for(int t=0;t<T;t++)
			{
			boolean valid=true;
			String s=c.readLine();
			int hist[]=hist(s);
			for(int i=0;i<26;i++)
				{
				if(hist[i]%2!=0)
					valid=false;
				}
			if(valid)
				System.out.println("YES");
			else
				System.out.println("NO");
			}
		}
	public static int [ ] hist(String s)
		{
		int h[]=new int[26];
		for(int i=0;i<s.length();i++)
			{
			h[s.charAt(i)-'A']++;
			}
		return h;
		}
	}

//must declare new classes here
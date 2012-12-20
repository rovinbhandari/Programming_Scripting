import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String arg[])throws Exception
	{
		try
		{
		
		
		
		
		BufferedReader inn=new BufferedReader(new InputStreamReader(System.in));
		int r=1,b=1,g=1,w=1;
		int t=Integer.parseInt(inn.readLine());
		
		String str="";
		
		for(int test=0;test<t;test++)
		{
			
			
			try
			{
			r=0;
			b=0;
			g=0;
			w=0;
			str=inn.readLine();
			
			}catch(Exception ee){}
			
			
			for(int i=0;i<str.length();i++)
			{
			
			if(str.charAt(i)=='R')
				r=r+1;
			if(str.charAt(i)=='B')
				b++;	
			if(str.charAt(i)=='G')
				g++;
			if(str.charAt(i)=='W')
				w++;
			}
			
			if( (r%2==0)&&(b%2==0)&&(g%2==0)&&(w%2==0) )
				System.out.println("YES");
			else
				System.out.println("NO");
			
		}
		
		}catch(Exception ee){
			ee.printStackTrace();}		
	}
}
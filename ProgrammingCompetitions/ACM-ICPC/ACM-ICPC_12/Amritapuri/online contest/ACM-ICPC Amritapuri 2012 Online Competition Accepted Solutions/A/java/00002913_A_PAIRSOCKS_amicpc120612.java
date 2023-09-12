import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class socks {

	
	public static void main(String[] args) throws Exception
	{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int testcases=Integer.parseInt(br.readLine());
		
		PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
			
		for(int i=0;i<testcases;i++)
		{
			int r=0,g=0,b=0,w=0;
			
			String input=new String(br.readLine());
			
			for(int j=0;j<input.length();j++)
			{
				if(input.charAt(j)=='R')
					r++;
				else
					if(input.charAt(j)=='B')
						b++;
					else
						if(input.charAt(j)=='W')
							w++;
						else
							if(input.charAt(j)=='G')
								g++;
				
			
					
			}
			if((r%2==0)&&(b%2==0)&&(w%2==0)&&(g%2==0))
				pw.println("YES");
			else
				pw.println("NO");
			
		}
			
			pw.flush();
			pw.close();
			
		}
	}


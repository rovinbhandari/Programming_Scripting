import java.io.*;


class ICPCONE
{
	public static void main(String arg[])throws IOException
	{
		try
		{
			int bCnt=0,rCnt=0,wCnt=0,gCnt=0;
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			
			int T=Integer.parseInt(br.readLine());
			int check[]=new int [T];
			String c[]=new String [T];
			for(int i=0;i<T;i++)
			{
				c[i]=br.readLine();
				if(c[i].length()>50) throw new Exception("ERROR");
				for(int j=0;j<c[i].length();j++)
				{
					switch(c[i].charAt(j))
					{
						case 'r':
						case 'R':
						rCnt=rCnt+1;
						break;

						case 'g':
						case 'G':
						gCnt=gCnt+1;
						break;
	
						case 'w':
						case 'W':
						wCnt=wCnt+1;
						break;
	
						case 'b':
						case 'B':
						bCnt=bCnt+1;
						break;
						default: throw new Exception("not rgbw");
					}
				}
				int flag=0;
				if((rCnt%2!=0))
				{
						check[i]=0;
						flag=1;
				}
				if((bCnt%2!=0))
				{
						check[i]=0;
						flag=1;
				}
				if((gCnt%2!=0))
				{
						check[i]=0;
						flag=1;
				}
				if((wCnt%2!=0))
				{
						check[i]=0;
						flag=1;
				}
				if(flag==0)
				check[i]=1;
				flag=0;
				bCnt=rCnt=wCnt=gCnt=0;
				
			}
			for(int i=0;i<T;i++)
			{
				if(check[i]==0)
					System.out.print("NO\n");
				else
					System.out.print("YES\n");
		
			}
				
			
			
			
			
		}
		catch(Exception ae)
		{
			System.out.print(""+ae);
		}
		
	}
	
}

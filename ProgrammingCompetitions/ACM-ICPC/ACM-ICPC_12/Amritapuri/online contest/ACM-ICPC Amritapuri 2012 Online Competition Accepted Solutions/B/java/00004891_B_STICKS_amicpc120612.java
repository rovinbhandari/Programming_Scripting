import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.StringReader;


public class problem2 {
	
	public static void main(String[] args) throws Exception
	{
		
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int testcases=Integer.parseInt(br.readLine());
		
		PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
			
		for(int i=0;i<testcases;i++)
		{
			StreamTokenizer st=new StreamTokenizer(new StringReader(br.readLine()));
			st.nextToken();
			int N=(int)st.nval;
			st.nextToken();
			int M=(int)st.nval;
			
			int[] sticks=new int[N];
			long cuboid=Integer.MIN_VALUE;
			
			for(int j=0;j<N;j++)
			{
				sticks[j]=Integer.parseInt(br.readLine());
			}
			
			for(int k=0;k<M;k++)
			{
				long l,w,h;
				st=new StreamTokenizer(new StringReader(br.readLine()));
				st.nextToken();
				l=(long)st.nval;
				st.nextToken();
				w=(long)st.nval;
				st.nextToken();
				h=(long)st.nval;
				
				long temp=(l*l)+(w*w)+(h*h);
				temp=(long)Math.sqrt(temp);
				
				if(cuboid<temp)
				cuboid=temp;
			}
			
			
				int count=0;
				for(int k=0;k<N;k++)
				{
					if(sticks[k]<=cuboid)
						count++;
				}
			
			
			br.readLine();
			pw.println(count);
		}
		
		pw.flush();
		pw.close();
		
	}

}

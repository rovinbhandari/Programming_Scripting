import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.StringReader;


public class problem3 {
	
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
				int L=(int)st.nval;
				st.nextToken();
				int H=(int)st.nval;
				
				int[] array=new int[N];
				
				st=new StreamTokenizer(new StringReader(br.readLine()));
				
				for(int j=0;j<N;j++)
				{
					st.nextToken();
					array[j]=(int)st.nval;
				}
				int count=0;
				for(int j=0;j<(N-2);j++)
				{
					int temp1=array[j];
					
					if(temp1>=H)
						continue;
					
					for(int k=(j+1);k<(N-1);k++)
					{
					int	temp2=array[k];
					
					if((temp1+temp2)>=H)
						continue;
					
						for(int l=(k+1);l<N;l++)
						{
							int temp=temp1+temp2+array[l];
							if((temp>=L)&&(temp<=H))
								count++;
						}
					}
				}
				
				pw.println(count);
			}
			pw.flush();
			pw.close();
		}

}
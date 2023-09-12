import java.io.*;
import java.util.Scanner;

public class ProgC {
	
	public static void main(String args[]) throws NumberFormatException, IOException 
	{
	
		int i,j,k,p,q,cnt,test,n,l,h,sum1,sum2;
		int arr[]=new int[1000];
		
		
	/*
	try {
			System.setIn(new FileInputStream("E:\\GWT\\Project\\Code\\src\\in.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		*/
	
		//BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
	
		Scanner inp=new Scanner(System.in);
		test=inp.nextInt();
		
		
		for (p=0;p<test;p++)
		{
			cnt=0;
			n=inp.nextInt();
			l=inp.nextInt();
			h=inp.nextInt();
			
			for (q=0;q<n;q++)
				arr[q]=inp.nextInt();
						
			for(i=0;i<n-2;i++)
			{
				if(arr[i]>h)
					continue;
				for (j=i+1;j<n-1;j++)
				{
					sum1=arr[i]+arr[j];
					if(sum1>h)
						continue;
					for (k=j+1;k<n;k++)
					{
						sum2 = sum1+arr[k];
						if (l<=sum2 && h>=sum2)
							cnt++;
					}
				}
			}
			
			System.out.println(cnt);
		}
	}
}


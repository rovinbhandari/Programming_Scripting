import java.util.Scanner;


public class Main {

	public static void main(String [] args)
	{
		Scanner s=new Scanner(System.in);
		
		
		int testcases=Integer.parseInt(s.nextLine());
		
		for(int i=0;i<testcases;i++)
		{
			String a=s.nextLine();
			int c1=0;
			int c2=0;
			int c3=0;
			int c4=0;
			for(int j=0;j<a.length();j++)
			{
				if(a.charAt(j)=='R')
					c1++;
				else if(a.charAt(j)=='G')
					c2++;
				else if(a.charAt(j)=='B')
					c3++;
				else
					c4++;
					
			}
			if(c1%2==0 && c2%2==0 && c3%2==0 && c4%2==0)
				System.out.println("YES");
			else
				System.out.println("NO");
			
		}
	}
}

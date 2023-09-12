import java.util.Scanner;


public class solutuion1 {
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		
		int t=scan.nextInt();
		
		while(t--!=0)
		{
			String str=scan.next();
			int clr[]=new int[4];
			int l=str.length();
			
			for(int i=0;i<l;i++)
			{
				String tmp=str.substring(i,i+1);
				if(tmp.equals("R"))
					clr[0]++;
				else if(tmp.equals("G"))
					clr[1]++;
				else if(tmp.equals("B"))
					clr[2]++;
				else if(tmp.equals("W"))
					clr[3]++;
					
			}
			
			if(clr[0]%2==0 && clr[1]%2==0 && clr[2]%2==0 && clr[3]%2==0 )
				System.out.println("YES");
			else
				System.out.println("NO");
			
			
		}
	}

}

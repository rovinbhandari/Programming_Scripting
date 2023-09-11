import java.util.Scanner;


public class PP1_2012 {

	public static void main(String []args)
	{
		Scanner a=new Scanner(System.in);
		String st =a.nextLine();
		int num=Integer.parseInt(st);
//		System.out.println(num+ " is the NUmber");
		
		for(int i=0;i<num;i++)
		{
			int count_red=0;
			int count_blue=0;
			int count_green=0;
			int count_white=0;
			String str=a.nextLine();
//			System.out.println(str);
			char[] ar= str.toCharArray();
			for(int j=0;j<ar.length;j++)
			{
				if(ar[j]=='R')
					count_red++;
				else if(ar[j]=='B')
					count_blue++;
				else if(ar[j]=='G')
					count_green++;
				else if(ar[j]=='W')
					count_white++;
			}
			
//			System.out.println(count_red+" Red");
//			System.out.println(count_blue+" Blue");
//			System.out.println(count_green+" Green");
//			System.out.println(count_white+" White");
			
			if(count_red%2==0 && count_blue%2==0 && count_green%2==0 && count_white%2==0)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}

import java.util.Scanner;
class A
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0)
		{
			String str=sc.next();
			int red=0,green=0,blue=0,white=0;
			for(int i=0;i<str.length();i++)
		{
			switch(str.charAt(i)){
			case 'R':
			red++;
				break;
			case 'B':
			blue++;
				break;
			case 'W':
			white++; break;
			case 'G':
			green++;
			break;
			default:continue;
			}

		}
		if(red%2==0&&blue%2==0&&green%2==0&&white%2==0)
			System.out.println("YES");
else System.out.println("NO");
}
}
}		

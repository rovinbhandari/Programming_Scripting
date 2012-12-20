import java.util.*;//neel
 public class main {
	public static void main(String[] args) {

				Scanner sc=new Scanner(System.in);
				int n=sc.nextInt();
				String s=sc.nextLine();
				if(n>=1 && n<=1000)
				{
				
				for(int j=1;j<=n;j++)
				{
				 s=sc.nextLine();

				 int r=0,g=0,b=0,w=0;
				char[] a=s.toCharArray();
				for(int i=0;i<a.length;i++)
				{
					if(a[i]=='R' )
						r++;
					else
						if(a[i]=='G' )
							g++;
						else
							if(a[i]=='B' )
								b++;
							else
					if(a[i]=='W')
						w++;
						
				}
				if(r%2==0 && g%2==0 && b%2==0 && w%2==0 )
					System.out.println("YES");
				else
					System.out.println("NO");
				}
				 
				}
				
	}

}

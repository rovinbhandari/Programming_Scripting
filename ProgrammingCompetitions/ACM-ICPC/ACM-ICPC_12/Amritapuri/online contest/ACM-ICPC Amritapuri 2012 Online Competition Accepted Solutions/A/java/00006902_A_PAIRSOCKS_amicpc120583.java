import java.util.Scanner;


public class socks {
	static Scanner sc = new Scanner(System.in);
	static int t=0;
	public static void main(String args[]) {
		t = sc.nextInt();
		int quit = 1;
		int count[] = new int[4];
		
		if (t>=1 && t<=1000) {
			for (int j=0; j<t; j++) {
				for (int i=0; i<4; i++)
					count[i] = 0;
				quit = 1;
				String c = sc.next();
				int len = c.length();
				if (len <= 50) {
					for (int i=0; i<len; i++) {
						switch(c.charAt(i)) {
						case 'R': 
							count[0]++;
							quit = 0;
							break;
						case 'G':
							count[1]++;
							quit=0;
							break;
						case 'B':
							count[2]++;
							quit=0;
							break;
						case 'W':
							count[3]++;
							quit=0;
							break;
						default:
							quit=1;
							break;
						}
						if (quit==1)
							break;
					}
				}
				if (quit == 0 && count[0]%2==0 && count[1]%2==0 && count[2]%2==0 && count[3]%2==0)
					System.out.println("YES");
				else 
					System.out.println("NO");
			}
		}
	}
}

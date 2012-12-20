import java.util.Scanner;


public class test3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int t,testcases;
		int a,b,c,d;
		String input = new String();
		Scanner in = new Scanner(System.in);
		testcases = in.nextInt();
		for(t=0;t<testcases;t++){
			a=0;b=0;c=0;d=0;
			input = in.next();
			for(int k=0;k<input.length();k++){
				if(input.charAt(k)=='R'){
					a++;
				}
				if(input.charAt(k)=='G'){
					b++;
				}
				if(input.charAt(k)=='B'){
					c++;
				}
				if(input.charAt(k)=='W'){
					d++;
				}
			}
			
			if((a&1)==0 && (b&1)==0 && (c&1)==0 && (d&1)==0){
				System.out.println("YES");
				
			}
			else
				System.out.println("NO");
		}
	}

}

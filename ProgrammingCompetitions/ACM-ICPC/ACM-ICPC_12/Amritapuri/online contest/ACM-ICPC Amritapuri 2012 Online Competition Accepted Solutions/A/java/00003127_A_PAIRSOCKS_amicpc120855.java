import java.util.*;
import java.io.*;

public class PairSocks {
	public static void main(String args[]) throws IOException {
		Scanner c = new Scanner(System.in);
		int T = c.nextInt();
		
		for (int t = 0; t < T; t++) {
			String s = c.next();
			int hash[] = new int[4];
			for (int i = 0; i < s.length(); i++) {
				if(s.charAt(i)=='R'){
					hash[0]++;
				}
				if(s.charAt(i)=='G'){
					hash[1]++;
				}
				if(s.charAt(i)=='B'){
					hash[2]++;
				}
				if(s.charAt(i)=='W'){
					hash[3]++;
				}
			}
			if((hash[0]%2==0) && (hash[1]%2==0) && (hash[2]%2==0) && (hash[3]%2==0)){
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}
}
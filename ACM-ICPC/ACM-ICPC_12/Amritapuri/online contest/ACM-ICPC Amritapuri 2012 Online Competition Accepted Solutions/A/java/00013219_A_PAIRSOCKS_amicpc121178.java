import java.util.Scanner;

public class PairOfScoks {
    public static void main(String[] args) {
        int n, k, rr=0, gr = 0, br = 0, wr = 0;
        Scanner sin = new Scanner(System.in);
        n = sin.nextInt();
        if (( n < 0 ) || (n > 1000))
            System.out.println("NO");
        String[] s = new String[n];
        for (k = 0; k < n; k++) {
            s[k] = sin.next();
        }
        for(k = 0; k< n; k++) {
            if(s[k].length() > 50)
                System.out.println("NO");
            else {
                rr = s[k].replaceAll("R","").length();
                gr = s[k].replaceAll("G","").length();
                br = s[k].replaceAll("B","").length();
                wr = s[k].replaceAll("W","").length();
                if((rr % 2 == 0) && (gr % 2 == 0) && (br % 2 == 0) && (wr % 2 == 0))
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }
    }
}
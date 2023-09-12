import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        String s[];
        int n, m;
        for (int i = 0; i < t; i++) {
            int count = 0;
            long d,max = 0;
            s = br.readLine().split(" ");
            n = Integer.parseInt(s[0]);
            m = Integer.parseInt(s[1]);
            int x[] = new int[n];
            for (int j = 0; j < n; j++) {
                x[j] = Integer.parseInt(br.readLine());
            }
            for (int k = 0; k < m; k++) {
                s = br.readLine().split(" ");
                long l = Integer.parseInt(s[0]);
                long b = Integer.parseInt(s[1]);
                long h = Integer.parseInt(s[2]);
                d = (int) Math.sqrt(l * l + b * b + h * h);
                max = Math.max(max, d);
            }
            for (int j = 0; j < n; j++) {

                if (x[j] <= max) {
                    count++;
                }
            }
            System.out.println(count);
            if(i!=t-1)
            s = br.readLine().split("");
        }

    }
}

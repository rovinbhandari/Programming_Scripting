
import java.io.BufferedReader;
import java.io.InputStreamReader;

class acm1 {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String st;
        int i, r, g, b, w, t, n;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            r = 0;
            g = 0;
            b = 0;
            w = 0;
            st = br.readLine();
            for (i = 0; i < st.length(); i++) {
                char c = st.charAt(i);
                if (c == 'R') {
                    r++;
                } else if (c == 'G') {
                    g++;
                } else if (c == 'B') {
                    b++;
                } else if (c == 'W') {
                    w++;
                }
            }
            if ((r % 2 == 0) && (g % 2 == 0) && (b % 2 == 0) && (w % 2 == 0)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
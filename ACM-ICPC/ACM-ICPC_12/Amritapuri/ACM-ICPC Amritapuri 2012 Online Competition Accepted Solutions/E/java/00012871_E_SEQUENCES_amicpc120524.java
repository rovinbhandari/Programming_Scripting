import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        int testCount = in.readInt();
        for (int i = 1; i <= testCount; ++i)
            solver.solve(i, in, out);
        out.close();
    }
}

class Task {
    int N;
    char[] S;
    int[] A;
    int[] Z;
    int[] O;
    int[] M;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        N = in.readInt();
        S = in.readString().toCharArray();
        //S = generate(1 << testNumber).toCharArray();
        //System.err.println(new String(S));
        //N = S.length;
        Z = new int[N + 1];
        O = new int[N + 1];
        A = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            Z[i] = Z[i - 1];
            O[i] = O[i - 1];
            if (S[i - 1] == '0') ++Z[i];
            else ++O[i];
            A[i] = Z[i] - O[i];
        }
        M = new int[10 * N];
        initialize(1, 1, N);
        int q = in.readInt();
        /*
        for (int a = 1; a <= N; ++a) {
            for (int b = a; b <= N; ++b) {
                int res = Math.max(Math.max(O[b] - O[a - 1], Z[b] - Z[a - 1]), O[b] - Z[a - 1] + query(1, 1, N, a - 1, b));
                if (res != LIS(a, b)) {
                    System.err.println("FAIL");
                    System.err.println(new String(S));
                    System.err.println(a + " " + b);
                    System.err.println(res + " " + LIS(a, b));
                }
            }
        }
        */
        for (int i = 0; i < q; ++i) {
            int a = in.readInt();
            int b = in.readInt();
            out.println(Math.max(Math.max(O[b] - O[a - 1], Z[b] - Z[a - 1]), O[b] - Z[a - 1] + query(1, 1, N, a - 1, b)));
        }
    }

    /*
    public String generate(int len) {
        StringBuilder s = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < len; ++i) {
            if (random.nextDouble() <= 0.5) s.append('0');
            else s.append('1');
        }
        return s.toString();
    }

    public int LIS(int a, int b) {
        int res = 0;
        String t = new String(S).substring(a - 1, b);
        int[] dp = new int[t.length()];
        for (int i = 0; i < dp.length; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (!(t.charAt(j) == '1' && t.charAt(i) == '0')) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
    */

    public void initialize(int node, int b, int e) {
        if (b == e)
            M[node] = A[b];
        else {
            initialize(2 * node, b, (b + e) / 2);
            initialize(2 * node + 1, (b + e) / 2 + 1, e);
            if (M[2 * node] >= M[2 * node + 1])
                M[node] = M[2 * node];
            else
                M[node] = M[2 * node + 1];
        }
    }

    public int query(int node, int b, int e, int i, int j) {
        if (i > e || j < b)
            return -Integer.MIN_VALUE;
        if (b >= i && e <= j)
            return M[node];
        return Math.max(query(2 * node, b, (b + e) / 2, i, j), query(2 * node + 1, (b + e) / 2 + 1, e, i, j));
    }
}


class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public long readLong() {
        return Long.parseLong(readString());
    }

    public double readDouble() {
        return Double.parseDouble(readString());
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}
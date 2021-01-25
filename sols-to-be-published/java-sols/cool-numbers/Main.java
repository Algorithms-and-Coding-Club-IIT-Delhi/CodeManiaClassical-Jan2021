import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static final int mod = 1000000007;

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);

        int n = scan.nextInt();
        int c = scan.nextInt();

        int[][] dp = new int[n][10];

        for (int i = 0; i < 10; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int digit = 0; digit < 10; ++digit) {
                int l = Math.max(0, digit - c), r = Math.min(9, digit + c), x = 0;
                for (int j = l; j <= r; ++j) {
                    x += dp[i - 1][j];
                    if (x >= mod) {
                        x -= mod;
                    }
                }
                dp[i][digit] = x;
            }
        }

        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            ans += dp[n - 1][i];
            if (ans >= mod)
                ans -= mod;
        }

        out.print(ans + "\n");

        out.close();
    }

    // fast input
    static class Scanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public Scanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine();
                    if (line == null)
                        return null;
                    tokenizer = new StringTokenizer(line);
                } catch (Exception e) {
                    throw(new RuntimeException());
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    // fast output
    static class OutputWriter {
        BufferedWriter writer;

        public OutputWriter(OutputStream stream) {
            writer = new BufferedWriter(new OutputStreamWriter(stream));
        }

        public void print(int i) throws IOException {
            writer.write(i);
        }
        public void print(String s) throws IOException {
            writer.write(s);
        }
        public void print(char[] c) throws IOException {
            writer.write(c);
        }
        public void close() throws IOException {
            writer.close();
        }
    }
}

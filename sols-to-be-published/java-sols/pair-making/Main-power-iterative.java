import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static long power(long a, long n, long mod) {
        long res = 1;
        while (n != 0) {
            if ((n & 1) == 1)
                res = (res * a) % mod;
            n >>= 1;
            a = (a * a) % mod;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);

        long n = scan.nextInt();
        long k = scan.nextInt();
        long p = scan.nextInt();

        long ans = 0;

        for (long i = 1; i < p; ++i) {
            long j = (power(i * i % p, p - 2, p) * k) % p;
            ans += ((n + p - i) / p) * ((n + p - j) / p);
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

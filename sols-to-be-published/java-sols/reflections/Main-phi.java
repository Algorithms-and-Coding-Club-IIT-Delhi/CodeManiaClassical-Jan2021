import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);

        int[] phi = new int[100005];

        for (int i = 0; i < phi.length; ++i) {
            phi[i] = i;
        }

        for (int i = 2; i < phi.length; ++i) {
            if (phi[i] == i) {
                for (int j = i; j < phi.length; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }

        int q = scan.nextInt();
        while (q-- > 0) {
            int k = scan.nextInt();
            int b = scan.nextInt();
            int c = scan.nextInt();
            int d = scan.nextInt();
            if (k % 2 == 0) {
                out.print(c * phi[k + 2] + "\n");
            } else {
                out.print((b + d) * phi[k + 2] / 2 + "\n");
            }
        }

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

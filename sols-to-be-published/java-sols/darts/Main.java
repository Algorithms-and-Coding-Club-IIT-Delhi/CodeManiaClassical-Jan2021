import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);

        int n = scan.nextInt();
        int q = scan.nextInt();

        Pair<Integer, Integer>[] a = new Pair[n];

        for (int i = 0; i < n; ++i) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            a[i] = new Pair<Integer, Integer>(x, y);
        }

        Arrays.sort(a);

        int[] suffixMax = new int[n];
        suffixMax[n - 1] = a[n - 1].second;
        for (int i = n - 2; i >= 0; --i)
            suffixMax[i] = Math.max(suffixMax[i + 1], a[i].second.intValue());

        for (int i = 0; i < q; ++i) {

            int x = scan.nextInt();
            int y = scan.nextInt();
            int l = 0, r = n - 1, ans_x = -1;

            while (l <= r) {
                int m = l + (r - l) / 2;
                if (a[m].first >= x) {
                    ans_x = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            if (ans_x == -1) {
                out.print(-1 + "\n");

            } else {

                l = ans_x;
                r = n - 1;
                int ans_y = -1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (suffixMax[m] >= y) {
                        ans_y = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }

                if (ans_y == -1) {
                    out.print(-1 + "\n");
                } else {
                    out.print(a[ans_y].first + " " + a[ans_y].second + "\n");
                }
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

        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
    }

    // fast output
    static class OutputWriter {
        BufferedWriter writer;

        public OutputWriter(OutputStream stream) {
            writer = new BufferedWriter(new OutputStreamWriter(stream));
        }

        public void print(int i) throws IOException { writer.write(i); }
        public void print(String s) throws IOException { writer.write(s); }
        public void print(char[] c) throws IOException { writer.write(c); }
        public void close() throws IOException { writer.close(); }
    }


    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) &&
                !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        @Override
        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }

        public Pair<V, U> swap() {
            return makePair(second, first);
        }

        @Override
        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }
    }

}



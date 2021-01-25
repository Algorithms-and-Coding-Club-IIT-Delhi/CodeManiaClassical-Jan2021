import java.io.*;
import java.util.*;

public class Main {

    static int[] a;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> g, components;

    public static Comparator<Integer> compareByAReverse = new Comparator<Integer>() {
        public int compare(Integer x, Integer y) {
            return Integer.compare(a[y.intValue()], a[x.intValue()]);
        }
    };

    public static Comparator<ArrayList<Integer>> compareBySizeReverse = new Comparator<ArrayList<Integer>>() {
        public int compare(ArrayList<Integer> x, ArrayList<Integer> y) {
            return Integer.compare(y.size(), x.size());
        }
    };

    public static void main(String[] args) throws IOException {
    
        Scanner scan = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);

        int n = scan.nextInt();
        int m = scan.nextInt();

        g = new ArrayList<ArrayList<Integer>>();
        components = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; ++i) {
            g.add(new ArrayList<Integer>());
            components.add(new ArrayList<Integer>());
        }

        a = new int[n];
        visited = new boolean[n];

        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            a[i] = scan.nextInt();
        }

        for (int i = 0; i < m; ++i) {
            int u = scan.nextInt() - 1;
            int v = scan.nextInt() - 1;
            g.get(u).add(v);
            g.get(v).add(u);
        }

        int totalComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                visited[i] = true;
                while (q.size() != 0) {
                    int v = q.poll();
                    components.get(totalComponents).add(v);
                    for (int u : g.get(v)) {
                        if (!visited[u]) {
                            q.add(u);
                            visited[u] = true;
                        }
                    }
                }
                totalComponents++;
            }
        }

        ArrayList<Integer> indices = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            indices.add(i);
        }

        Collections.sort(indices, compareByAReverse);
        Collections.sort(components, compareBySizeReverse);

        int currentRank = 0;
        int[] assignedVertex = new int[n];

        for (int component = 0; component < totalComponents; ++component) {
            for (Integer x : components.get(component)) {
                assignedVertex[indices.get(currentRank).intValue()] = x.intValue() + 1;
                currentRank++;
            }
        }

        for (int x : assignedVertex) {
            out.print(x + " ");
        }
        out.print("\n");
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
}

import java.io.*;
import java.util.*;

public class Main {
    static int[] a;

    public static Comparator<Integer> compareByAReverse = new Comparator<Integer>() {
        public int compare(Integer x, Integer y) {
            return Integer.compare(a[y.intValue()], a[x.intValue()]);
        }
    };

    public static Comparator<ArrayList<Integer>> compareBySizeReverse =
        new Comparator<ArrayList<Integer>>() {
            public int compare(ArrayList<Integer> x, ArrayList<Integer> y) {
                return Integer.compare(y.size(), x.size());
            }
        };

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);

        int n = scan.nextInt();
        int m = scan.nextInt();

        a = new int[n];

        for (int i = 0; i < n; ++i) {
            a[i] = scan.nextInt();
        }

        DSU dsu = new DSU(n);

        for (int i = 0; i < m; ++i) {
            int u = scan.nextInt() - 1;
            int v = scan.nextInt() - 1;
            dsu.unionSets(u, v);
        }

        ArrayList<ArrayList<Integer>> components = dsu.getComponents();
        int totalComponents = components.size();

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

    static class DSU {
        int n;
        int[] par, siz;

        public DSU(int size) {
            n = size;
            par = new int[n];
            siz = new int[n];
            for (int i = 0; i < n; ++i) {
                makeSet(i);
            }
        }

        public void makeSet(int v) {
            par[v] = v;
            siz[v] = 1;
        }

        int findSet(int v) {
            if (v == par[v]) return v;
            par[v] = findSet(par[v]);
            return par[v];
        }

        void unionSets(int a, int b) {
            a = findSet(a);
            b = findSet(b);
            if (a != b) {
                if (siz[a] < siz[b]) {
                    int t = a;
                    a = b;
                    b = t;
                }
                par[b] = a;
                siz[a] += siz[b];
            }
        }

        ArrayList<ArrayList<Integer>> getComponents() {
            int[] representative = new int[n];
            int[] componentSize = new int[n];
            for (int i = 0; i < n; ++i) {
                representative[i] = findSet(i);
                componentSize[representative[i]]++;
            }
            ArrayList<Integer>[] components = new ArrayList[n];
            for (int i = 0; i < n; ++i) {
                components[i] = new ArrayList<Integer>(componentSize[i]);
            }
            for (int i = 0; i < n; ++i) {
                components[representative[i]].add(i);
            }
            ArrayList<ArrayList<Integer>> nonEmptyComponents = new ArrayList<ArrayList<Integer>>();
            for (ArrayList<Integer> component : components) {
                if (component.isEmpty()) continue;
                nonEmptyComponents.add(component);
            }
            return nonEmptyComponents;
        }

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

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int l = 1, r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            System.out.println(m);
            String s = scan.next();
            if (s.equals("guessed")) {
                break;
            } else if (s.equals("lesser")) {
                l = m + 1;
                r = m + (r + 1 - m) / 2;
            } else {
                l = l + (m - l) / 2;
                r = m - 1;
            }
        }
    }

}



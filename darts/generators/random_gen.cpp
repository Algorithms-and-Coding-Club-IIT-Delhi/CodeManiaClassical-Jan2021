#include <bits/stdc++.h>

#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int q = atoi(argv[2]);

    int m = int(1e9);

    cout << n << ' ' << q << endl;

    for (int i = 0; i < n + q; ++i) {
        int x = rnd.next(0, m);
        int y = rnd.next(0, m);
        cout << x << ' ' << y << '\n';
    }

    return 0;
}

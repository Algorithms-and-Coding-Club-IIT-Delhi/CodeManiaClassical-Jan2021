#include <iostream>

#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int indices = rnd.next(0, min(n, 10));
    vector<int> a(n);
    for (int i = 0; i < indices; ++i) {
        a[rnd.next(0, n - 1)] = rnd.next(0, 1'000'000);
    }
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

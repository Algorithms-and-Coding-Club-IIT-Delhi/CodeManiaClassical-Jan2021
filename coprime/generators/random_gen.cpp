#include <iostream>

#include "testlib.h"

using namespace std;

const int MAX = 1e6;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rnd.next(0, MAX) << " \n"[i == n - 1];
    }
    return 0;
}

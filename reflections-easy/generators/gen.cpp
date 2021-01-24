#include <iostream>

#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int q = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    cout << q << '\n';
    for (int i = 1; i <= q; ++i)
        cout << i << ' ' << b << ' ' << c << ' ' << d << '\n';
    return 0;
}

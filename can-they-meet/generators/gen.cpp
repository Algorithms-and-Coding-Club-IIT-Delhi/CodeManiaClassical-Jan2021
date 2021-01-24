#include <iostream>

#include "testlib.h"

using namespace std;

typedef long long int ll;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = atoi(argv[1]);
    ll lo = atoll(argv[2]), hi = atoll(argv[3]);

    cout << t << endl;
    for (int i = 0; i < t; i++) {
        ll a = rnd.next(lo, hi);
        ll b = rnd.next(lo, hi);
        ll c = rnd.next(lo, hi);

        cout << a << " " << b << " " << c << endl;
    }
}

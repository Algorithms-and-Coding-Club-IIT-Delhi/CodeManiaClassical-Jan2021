#include <iostream>
#include <vector>

#include "testlib.h"

using namespace std;

const long long MAX = 1e6;
const long long MAX_DISCOUNTED = 0.75e6;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    cout << n << '\n';

    const long long MAXPRE = ((long long)n) * MAX_DISCOUNTED;

    vector<long long> pre(n);

    for (auto& x : pre) {
        x = rnd.next(0LL, MAXPRE);
    }
    sort(pre.begin(), pre.end());
    for (int i = n - 1; i > 0; --i) {
        pre[i] -= pre[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << min(pre[i], MAX) << " \n"[i == n - 1];
    }
    return 0;
}

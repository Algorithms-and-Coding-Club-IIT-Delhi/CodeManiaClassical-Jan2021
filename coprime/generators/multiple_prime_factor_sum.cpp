#include <cassert>
#include <iostream>

#include "testlib.h"

using namespace std;

const int MAX = 1e6;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    cout << n << '\n';

    auto primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    long long max_sum = 1;

    for (auto& x : primes) {
        if (max_sum * x > n * MAX) {
            break;
        }
        max_sum *= x;
    }

    vector<long long> pre(n);

    pre.back() = max_sum;

    for (int i = 0; i < n - 1; ++i) {
        pre[i] = rnd.next(0LL, max_sum);
    }

    sort(pre.begin(), pre.end());

    for (int i = n - 1; i > 0; --i) {
        pre[i] -= pre[i - 1];
        assert(pre[i] <= MAX);
    }

    for (int i = 0; i < n; ++i) {
        cout << pre[i] << " \n"[i == n - 1];
    }

    return 0;
}

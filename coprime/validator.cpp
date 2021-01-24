#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int a = inf.readInt(0, 1'000'000);
        if (i == n - 1) inf.readEoln();
        else inf.readSpace();
        sum += a;
    }
    assert(sum != 0);
    inf.readEof();
}

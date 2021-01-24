#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 300'000, "n");
    inf.readSpace();
    int q = inf.readInt(1, 300'000, "q");
    inf.readEoln();
    for (int i = 0; i < n + q; ++i) {
        inf.readInt(0, (int)1e9, "x");
        inf.readSpace();
        inf.readInt(0, (int)1e9, "y");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}


#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int k = inf.readInt(1, 1000*1000*1000, "k");
    inf.readSpace();
    int n = inf.readInt(1, 1000*1000*1000, "n");
    inf.readEoln();
    ensure(k <= n);

    inf.readEof();    
}

#include <cmath>

#include "testlib.h"
bool isprime(int p) {
    if (p == 2) return true;
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) return false;
    }
    return true;
}
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000000000, "n");
    inf.readSpace();
    int k = inf.readInt(1, 99999, "k");
    inf.readSpace();
    int p = inf.readInt(2, 100000, "p");
    ensure(k < p);
    ensure(isprime(p));
    inf.readEoln();
    inf.readEof();
}

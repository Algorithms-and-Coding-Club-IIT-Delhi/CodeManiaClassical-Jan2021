#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long int mx1 = 10'000LL, mx2 = 1'000'000'000'000'000LL;
    int testCount = inf.readInt(1, mx1, "testCount");
    inf.readEoln();

    for (int i = 0; i < testCount; i++) {
        inf.readLong(0, mx2, "a");
        inf.readSpace();
        inf.readLong(0, mx2, "b");
        inf.readSpace();
        inf.readLong(0, mx2, "x");
        inf.readEoln();
    }

    inf.readEof();
}

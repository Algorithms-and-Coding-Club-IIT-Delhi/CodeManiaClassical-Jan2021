#include "testlib.h"
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "number of cities and groups");
    inf.readSpace();
    int m = inf.readInt(1, 100000, "number of roads");
    inf.readEoln();
    for (int i = 1; i < n; i++) {
        inf.readInt(1, 1000, "a_i");
        inf.readSpace();
    }
    inf.readInt(1, 1000, "a_i");
    inf.readEoln();
    for (int i = 1; i <= m; i++) {
        inf.readInt(1, n, "city 1");
        inf.readSpace();
        inf.readInt(1, n, "city 2");
        inf.readEoln();
    }
    inf.readEof();
}

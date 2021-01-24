#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 100'000, "testCount");
    inf.readEoln();
    for (int i = 0; i < testCount; i++) {
        int n = inf.readInt(0, 100'000, "n");
        inf.readSpace();
        inf.readInt(0, 1, "s_B");
        inf.readSpace();
        inf.readInt(0, 1, "s_C");
        inf.readSpace();
        inf.readInt(0, 1, "s_D");
        inf.readEoln();
    }

    inf.readEof();
}

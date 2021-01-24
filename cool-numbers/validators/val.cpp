#include "testlib.h"
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 100000, "n");
    inf.readSpace();
    inf.readInt(0, 9, "c");
    inf.readEoln();
    inf.readEof();
}

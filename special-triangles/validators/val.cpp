#include <map>
#include <vector>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readInt(1, 1000000000, "a");
    inf.readSpace();
    inf.readInt(1, 1000000000, "b");
    inf.readEoln();
    inf.readEof();
}

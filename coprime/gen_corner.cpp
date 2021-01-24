#include "testlib.h"
#include <iostream>
#include <vector>

auto main(int argc, char* argv[]) -> int {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    std::vector<int> a(n);
    a[rnd.next(0, n - 1)] = 1;
    std::cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}

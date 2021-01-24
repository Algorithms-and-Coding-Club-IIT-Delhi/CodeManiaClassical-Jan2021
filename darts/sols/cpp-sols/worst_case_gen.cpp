#include <iostream>

int main() {
    int n = 3e5;
    int q = 3e5;
    std::cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; ++i) std::cout << i << ' ' << n - 1 - i << '\n';
    for (int i = 0; i < n; ++i) std::cout << i << ' ' << n - 1 - i << '\n';
}

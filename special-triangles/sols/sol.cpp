#include <algorithm>
#include <iostream>

using u32 = uint_fast32_t;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    u32 a, b;
    std::cin >> a >> b;

    auto g = std::__gcd(a, b);
    a /= g, b /= g;

    if (b > 2) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (b == 1) a *= 2;

    std::cout << 1 << std::endl;

    std::cout << 0 << " " << 2 * a << " " << 2 << " " << a << " " << 3 << " "
              << 0 << " " << std::endl;

    return 0;
}

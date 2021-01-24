#include <iostream>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int q;
    std::cin >> q;

    while (q--) {
        long long a, b, x;
        std::cin >> a >> b >> x;

        if (a == 0 && b == 0) {
            std::cout << (x == 0) << '\n';
            continue;
        }

        long long g = std::gcd(a, b);
        if (x % 2 == 0) {
            if ((x / 2) % g == 0) {
                std::cout << 1 << '\n';
                continue;
            }
        }

        x -= a + b;
        if (x % 2 == 0) {
            if ((x / 2) % g == 0) {
                std::cout << 1 << '\n';
                continue;
            }
        }

        std::cout << 0 << '\n';
    }

    return 0;
}

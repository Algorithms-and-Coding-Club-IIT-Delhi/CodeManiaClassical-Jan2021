#include <iostream>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, x;
        std::cin >> a >> b >> x;
        if (a == 0 && b == 0) {
            std::cout << (x == 0) << '\n';
        } else {
            std::cout << (x % std::gcd(a + b, a - b) == 0) << '\n';
        }
    }
    return 0;
}

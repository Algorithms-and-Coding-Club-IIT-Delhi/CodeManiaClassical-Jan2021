#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int q, k, b, c, d, ans = 0;
    std::cin >> q >> k >> b >> c >> d;
    for (int i = 0; i <= k + 2; ++i) {
        if (std::gcd(i, k + 2 - i) == 1) {
            if (i % 2 == 0) {
                if ((k + 2 - i) % 2 == 0) {
                    assert(false);
                } else {
                    ans += b;
                }
            } else {
                if ((k + 2 - i) % 2 == 0) {
                    ans += d;
                } else {
                    ans += c;
                }
            }
        }
    }
    std::cout << ans << std::endl;
}

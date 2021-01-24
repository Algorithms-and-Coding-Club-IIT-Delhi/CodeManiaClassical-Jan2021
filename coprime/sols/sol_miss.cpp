#include <algorithm>
#include <iostream>
#include <vector>

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i32 n;
    std::cin >> n;
    std::vector<i64> pre(n);

    i64 p = 0;
    for (auto &&x : pre) {
        std::cin >> x;
        p += x;
        x = p;
    }

    if (n == 1 && pre[0] == 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    i32 max_chain = 1;

    auto update = [&](i64 prime) {
        i32 divisible = 0;
        for (auto &&x : pre) divisible += ((x % prime) == 0);
        max_chain = std::max(max_chain, divisible);
    };

    for (i32 i = 2; (i64)i * i <= p; ++i) {
        if (p % i == 0) {
            while (p % i == 0) p /= i;
            update(i);
        }
    }

    if (p > 1) update(p);

    std::cout << n - max_chain << std::endl;

    return 0;
}

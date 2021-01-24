#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using i32 = int_fast32_t;
using T = i32;
const T EMPTY_MAX = std::numeric_limits<T>::min();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i32 n, q;
    std::cin >> n >> q;

    std::vector<std::pair<T, T>> a(n);
    for (auto&& [x, y] : a) std::cin >> x >> y;
    std::sort(begin(a), end(a));

    std::vector<T> y(n);
    std::transform(std::begin(a), std::end(a), std::begin(y),
                   [](const auto& p) { return p.second; });

    std::vector<T> suffix_max(n);
    std::partial_sum(std::rbegin(y), std::rend(y), std::rbegin(suffix_max),
                     [](const T& a, const T& b) { return std::max(a, b); });

    while (q--) {
        T x, y;
        std::cin >> x >> y;
        auto it_x = std::lower_bound(std::begin(a), std::end(a),
                                     std::make_pair(x, EMPTY_MAX));
        if (it_x == std::end(a)) {
            std::cout << -1 << '\n';
        } else {
            auto it_start =
                std::begin(suffix_max) + std::distance(std::begin(a), it_x);
            auto it_y =
                std::upper_bound(it_start, std::end(suffix_max), y,
                                 [](const T& a, const T& b) { return a > b; });
            if (it_y == it_start) {
                std::cout << -1 << '\n';
            } else {
                auto it_ans = std::begin(a) +
                              std::distance(std::begin(suffix_max), it_y) - 1;
                std::cout << it_ans->first << ' ' << it_ans->second << '\n';
            }
        }
    }
    return 0;
}

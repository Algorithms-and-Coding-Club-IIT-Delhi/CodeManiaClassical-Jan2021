#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#define DEBUG 0

using i32 = int_fast32_t;
using T = i32;
using Coordinates = std::pair<T, T>;
using CoordinatesList = std::vector<Coordinates>;

const T EMPTY_MAX = std::numeric_limits<T>::min();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i32 n, q;
    std::cin >> n >> q;

    CoordinatesList a(n);
    for (auto&& [x, y] : a) std::cin >> x >> y;

    std::sort(begin(a), end(a));

    auto dominates = [](const Coordinates& p, const Coordinates& q) {
        return p.first >= q.first && p.second >= q.second;
    };

    while (q--) {
        T x, y;
        std::cin >> x >> y;

        i32 l = 0, r = (i32)a.size() - 1;
        i32 dominating_index = -1;

        while (l <= r) {
            i32 m = l + ((r - l) >> 1);
            if (x <= a[m].first) {
                dominating_index = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (dominating_index == -1) {
            std::cout << -1 << '\n';
        } else {
            T ans_x, ans_y;
            std::tie(ans_x, ans_y) = a[dominating_index];
            if (dominates(a[dominating_index], std::make_pair(x, y))) {
                std::cout << ans_x << ' ' << ans_y << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}

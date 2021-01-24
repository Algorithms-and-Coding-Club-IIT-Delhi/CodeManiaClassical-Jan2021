#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#define DEBUG 0

using i32 = int_fast32_t;
using T = i32;  // replace this by int_fast64_t if data doesn't fit in 32 bit
                // signed ints
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

    auto dominates = [](const Coordinates& p, const Coordinates& q) {
        return p.first >= q.first && p.second >= q.second;
    };

    while (q--) {
        T x, y;
        std::cin >> x >> y;
        Coordinates c{x, y};
        bool found = false;

        for (auto& p : a) {
            if (dominates(p, c)) {
                std::cout << p.first << ' ' << p.second << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}

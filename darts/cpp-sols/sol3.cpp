#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cassert>

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
    for (auto &&[x, y] : a)
        std::cin >> x >> y;

    std::sort(begin(a), end(a));

    std::vector<char> possible(n, 1);

    std::function<void(const i32&, const i32&)> find_maximal =
        
        [&] (const i32& l, const i32& r) {
            
            if (l >= r)
                return;
            
            i32 m = l + ((r - l) >> 1);
            find_maximal(l, m);
            find_maximal(m + 1, r);
            
            T max_second = EMPTY_MAX;

            for (int i = m + 1; i <= r; ++i)
                if (possible[i])
                    max_second = std::max(max_second, a[i].second);
            
            for (int i = l; i <= m; ++i)
                if (possible[i] && a[i].second <= max_second)
                    possible[i] = 0;
        };

    find_maximal(0, n - 1);
    i32 total = 0;
    for (i32 i = 0; i < n; ++i)
        total += possible[i];
    CoordinatesList maximal_vectors(total);
    for (i32 i = 0; i < n; ++i)
        if (possible[i])
            maximal_vectors[--total] = a[i];

#if DEBUG
    
    std::cerr << "Maximal vectors" << std::endl;

    for (auto &&[x, y] : maximal_vectors)
        std::cerr << x << ' ' << y << '\n';
    
    for (size_t i = 0; i + 1 < maximal_vectors.size(); ++i) {
        assert(maximal_vectors[i].first > maximal_vectors[i + 1].first);
        assert(maximal_vectors[i].second < maximal_vectors[i + 1].second);
    }
    
    std::cerr << "Query answers" << std::endl;

#endif

    auto dominates = [] (const Coordinates& p, const Coordinates& q) {
        return p.first >= q.first && p.second >= q.second;
    };

    while (q--) {
        
        T x, y;
        std::cin >> x >> y;
        
        i32 l = 0, r = (i32) maximal_vectors.size() - 1;
        i32 dominating_index = -1;
        
        while (l <= r) {
            i32 m = l + ((r - l) >> 1);
            if (x <= maximal_vectors[m].first) {
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
            std::tie(ans_x, ans_y) = maximal_vectors[dominating_index];
            if (dominates(maximal_vectors[dominating_index], std::make_pair(x, y))) {
                std::cout << ans_x << ' ' << ans_y << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}

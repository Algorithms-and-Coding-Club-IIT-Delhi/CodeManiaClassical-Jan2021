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

    std::function<CoordinatesList(const CoordinatesList&)> find_maximal =
        
        [&find_maximal] (const CoordinatesList& a) {
            
            size_t n = a.size();
            
            if (n <= 1)
                return a;
            
            auto l_maximal = find_maximal(CoordinatesList(begin(a), begin(a) + n / 2));
            auto r_maximal = find_maximal(CoordinatesList(begin(a) + n / 2, end(a)));
            
            T max_second = EMPTY_MAX;
            
            for (auto &[x, y] : r_maximal)
                max_second = std::max(max_second, y);
            
            for (auto &[x, y] : l_maximal)
                if (y > max_second)
                    r_maximal.emplace_back(x, y);

            return r_maximal;
        };

    CoordinatesList maximal_vectors = find_maximal(a);

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
        Coordinates c{x, y};
        bool found = false;

        // on random outputs, the size of the maximal set will be sub-linear
        // and it might be easy to do this

        for (auto &p : maximal_vectors) {
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

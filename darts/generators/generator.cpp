#include "testlib.h"

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cassert>

std::vector<std::pair<int, int>> generate_pareto_boundary(int n, int convexity, int r = 1e9) {

    std::vector<int> x(10 * n), y(10 * n);
    
    for (auto &t : x) t = rnd.wnext(r, convexity);
    for (auto &t : y) t = rnd.wnext(r, convexity);
    
    sort(begin(x), end(x));
    sort(rbegin(y), rend(y));
    
    x.resize(unique(begin(x), end(x)) - begin(x));
    y.resize(unique(begin(y), end(y)) - begin(y));
    
    int sample_size = std::min(x.size(), y.size());

    assert(sample_size >= n);

    std::vector<std::pair<int, int>> p(sample_size), q(n);
    for (int i = 0; i < sample_size; ++i)
        p[i] = {x[i], y[i]};
    shuffle(p.begin(), p.end());
    
    for (int i = 0; i < n; ++i)
        q[i] = p[i];

    return q;

}

int main(int argc, char* argv[]) {

    // registerGen(argc, argv, 1);
    rnd.setSeed(1089);

    int n = atoi(argv[1]);
    int q = atoi(argv[2]);
    int type_n = atoi(argv[3]);
    int type_q = atoi(argv[4]);
    int convexity = atoi(argv[5]);
    int sz = n;

    switch (type_n) {
        case 1: {
                    sz = 1;
                    break;
                }
        case 2: {
                    sz = 10;
                    break;
                }
        case 3: {
                    sz = n / 2;
                    break;
                }
        case 4: {
                    sz = n - 10;
                    break;
                }
        case 5: {
                    sz = n - 1;
                    break;
                }
        case 6: {
                    sz = n;
                    break;
                }
    }

    auto given_set = generate_pareto_boundary(sz, convexity);
    auto pareto_boundary = given_set;
    sort(begin(pareto_boundary), end(pareto_boundary));

    for (int i = 0; i + 1 < (int) pareto_boundary.size(); ++i) {
        assert(pareto_boundary[i].first < pareto_boundary[i + 1].first);
        assert(pareto_boundary[i].second > pareto_boundary[i + 1].second);
    }

    for (int i = 0; i < n - sz; ++i) {
        int index = rnd.next(0, sz - 1);
        int choose_corner = rnd.next(0, 10000);
        int l, r;
        if (choose_corner < 200) {
            l = given_set[index].first;
            r = rnd.next(given_set[index].second);
        } else if (choose_corner < 400) {
            l = rnd.next(given_set[index].first);
            r = given_set[index].second;
        } else if (choose_corner < 405) {
            std::tie(l, r) = (given_set[index]);
        } else {
            l = rnd.next(given_set[index].first);
            r = rnd.next(given_set[index].second);
        }
        given_set.emplace_back(l, r);
    }

    assert(n == given_set.size());
    std::cout << n << ' ' << q << std::endl;
    for (auto &[x, y] : given_set) {
        std::cout << x << ' ' << y << '\n';
    }

    std::vector<std::pair<int, int>> queries;

    for (int i = 0; i < q / 2; ++i) {
        int x = rnd.next(int(1e9));
        int y = rnd.next(int(1e9));
        queries.emplace_back(x, y);
    }

    // left of pareto optimal
    if (type_q & 1) {
        for (int i = 0; i < q; ++i) {
            int index = rnd.next(0, sz - 1);
            int chosen_x = rnd.next(0, pareto_boundary[index].first);
            int chosen_y = rnd.next(0, pareto_boundary[index].second);
            queries.emplace_back(chosen_x, chosen_y);
        }
    }

    // right of pareto optimal
    if (type_q & 2) {
        for (int i = 0; i < q; ++i) {
            int index = rnd.next(0, sz - 1);
            int chosen_x = rnd.next(pareto_boundary[index].first, int(1e9));
            int chosen_y = rnd.next(pareto_boundary[index].second, int(1e9));
            queries.emplace_back(chosen_x, chosen_y);
        }
    }

    // between pareto optimal and on point
    if (type_q & 4) {
        if (sz == 1) {
            for (int i = 0; i < q; ++i) {
                int index = rnd.next(0, sz - 1);
                queries.emplace_back(pareto_boundary[index]);
            }
        } else {
            for (int i = 0; i < q; ++i) {
                int choice = rnd.next(100);
                if (choice < 5) {
                    int index = rnd.next(0, sz - 1);
                    queries.emplace_back(pareto_boundary[index]);
                } else {
                    int index = rnd.next(0, sz - 2);
                    int random_x = rnd.next(pareto_boundary[index].first, pareto_boundary[index + 1].first);
                    int random_y = rnd.next(pareto_boundary[index + 1].second, pareto_boundary[index].second);
                    queries.emplace_back(random_x, random_y);
                }
            }
        }
    }

    shuffle(begin(queries), end(queries));

    for (int i = 0; i < q; ++i) {
        std::cout << queries[i].first << ' ' << queries[i].second << '\n';
    }

    return 0;

}

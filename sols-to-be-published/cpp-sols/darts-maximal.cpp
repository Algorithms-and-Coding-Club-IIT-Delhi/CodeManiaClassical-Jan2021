#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    for (auto &&[x, y] : a)
        cin >> x >> y;
    sort(begin(a), end(a));

    function<vector<int>(const int, const int)> find_maximal =
        
        [&] (const int l, const int r) {
            if (l == r)
                return vector<int>{l};
            int m = l + ((r - l) >> 1);
            auto l_maximal = find_maximal(l, m);
            auto r_maximal = find_maximal(m + 1, r);
            int max_second = 0;
            for (const auto i : r_maximal)
                max_second = max(max_second, a[i].second);
            for (const auto i : l_maximal)
                if (a[i].second > max_second)
                    r_maximal.push_back(i);
            return r_maximal;
        };

    vector<int> indices = find_maximal(0, n - 1);
    vector<pair<int, int>> maximal_vectors(indices.size());
    for (int i = 0; i < (int) indices.size(); ++i)
        maximal_vectors[i] = a[indices[i]];

    while (q--) {
        
        int x, y;
        cin >> x >> y;
        int l = 0, r = (int) maximal_vectors.size() - 1;
        int dominating_index = -1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (x <= maximal_vectors[m].first) {
                dominating_index = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (dominating_index == -1) {
            cout << -1 << '\n';
        } else {
            int ans_x, ans_y;
            tie(ans_x, ans_y) = maximal_vectors[dominating_index];
            if (ans_y >= y) {
                cout << ans_x << ' ' << ans_y << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}

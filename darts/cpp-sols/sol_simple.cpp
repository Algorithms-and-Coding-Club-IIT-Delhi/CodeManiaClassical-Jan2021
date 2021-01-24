#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    sort(begin(a), end(a));

    vector<int> y(n);
    transform(begin(a), end(a), begin(y),
              [](const auto& p) { return p.second; });

    vector<int> suffix_max_y(n);
    partial_sum(rbegin(y), rend(y), rbegin(suffix_max_y),
                [](const int& a, const int& b) { return max(a, b); });

    while (q--) {
        int x, y;
        cin >> x >> y;
        auto it_x = lower_bound(begin(a), end(a), make_pair(x, INT_MIN));
        if (it_x == end(a)) {
            cout << -1 << '\n';
        } else {
            auto start_it = begin(suffix_max_y) + (it_x - begin(a));
            auto it_y = upper_bound(
                start_it, end(suffix_max_y), y,
                [](const int& a, const int& b) { return a > b; });
            if (it_y == start_it) {
                cout << -1 << '\n';
            } else {
                auto it_ans = begin(a) + (it_y - begin(suffix_max_y)) - 1;
                cout << it_ans->first << ' ' << it_ans->second << '\n';
            }
        }
    }

    return 0;
}

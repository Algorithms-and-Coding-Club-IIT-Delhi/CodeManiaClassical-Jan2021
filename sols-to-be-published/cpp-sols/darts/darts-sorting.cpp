#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

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

    vector<int> suffix_max(n);
    suffix_max[n - 1] = a[n - 1].second;
    for (int i = n - 2; i >= 0; --i) {
        suffix_max[i] = max(suffix_max[i + 1], a[i].second);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        auto it_x = lower_bound(begin(a), end(a), make_pair(x, 0));
        if (it_x == end(a)) {
            cout << -1 << '\n';
        } else {
            auto it_start = begin(suffix_max) + distance(begin(a), it_x);
            auto it_y =
                upper_bound(it_start, end(suffix_max), y,
                            [](const int& a, const int& b) { return a > b; });
            if (it_y == it_start) {
                cout << -1 << '\n';
            } else {
                auto it_ans = begin(a) + distance(begin(suffix_max), it_y) - 1;
                cout << it_ans->first << ' ' << it_ans->second << '\n';
            }
        }
    }

    return 0;
}

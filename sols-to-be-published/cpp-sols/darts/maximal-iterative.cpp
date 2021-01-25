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
    for (auto &[x, y] : a)
        cin >> x >> y;
    sort(a.rbegin(), a.rend());

    int y_max = -1;
    vector<pair<int, int>> maximal;
    maximal.reserve(n);

    for (auto &[x, y] : a)
        if (y_max < y)
            maximal.emplace_back(x, y), y_max = y;

    while (q--) {
        int x, y;
        cin >> x >> y;
        auto it = lower_bound(maximal.begin(), maximal.end(), y,
                                   [](const pair<int, int> &p,
                                      const int &y) { return p.second < y; });
        if (it == maximal.end() || it->first < x)
            cout << -1 << '\n';
        else
            cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}

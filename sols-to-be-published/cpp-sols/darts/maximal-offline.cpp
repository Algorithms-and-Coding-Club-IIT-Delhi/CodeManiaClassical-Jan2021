#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

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

    vector<tuple<int, int, int>> queries(q);
    q = 0;
    for (auto &[x, y, i] : queries)
        cin >> x >> y, i = q++;

    sort(queries.begin(), queries.end());
    vector<int> answer(q);

    int ptr = (int) maximal.size() - 1;
    for (auto &[x, y, i] : queries) {
        while ((~ptr) && maximal[ptr].first < x) --ptr;
        if ((~ptr) && maximal[ptr].second >= y) answer[i] = ptr;
        else answer[i] = -1;
    }

    for (auto x : answer) {
        if (x == -1) {
            cout << -1 << '\n';
        } else {
            cout << maximal[x].first << ' ' << maximal[x].second << '\n';
        }
    }

    return 0;
}

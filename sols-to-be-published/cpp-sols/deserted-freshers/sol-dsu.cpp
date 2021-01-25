#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

struct dsu {
    int n;
    vector<int32_t> par, siz;

    dsu(int n) : n(n), par(n), siz(n) {
        for (int i = 0; i < n; ++i) {
            make_set(i);
        }
    };

    inline void make_set(int32_t v) {
        par[v] = v;
        siz[v] = 1;
    }

    int32_t find_set(int32_t v) {
        if (v == par[v]) return v;
        return par[v] = find_set(par[v]);
    }

    void union_sets(int32_t a, int32_t b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (siz[a] < siz[b]) swap(a, b);
            par[b] = a;
            siz[a] += siz[b];
        }
    }

    vector<vector<int>> components() {
        vector<int> representative(n), component_size(n);
        for (int i = 0; i < n; ++i) {
            representative[i] = find_set(i);
            component_size[representative[i]]++;
        }
        vector<vector<int>> components(n);
        for (int i = 0; i < n; ++i) components[i].reserve(component_size[i]);
        for (int i = 0; i < n; ++i) components[representative[i]].push_back(i);
        components.erase(
            remove_if(components.begin(), components.end(),
                      [](const vector<int>& v) { return v.empty(); }),
            components.end());
        return components;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());

    dsu country(n);

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        country.union_sets(u - 1, v - 1);
    }

    auto components = move(country.components());

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](const int i, const int j) {
        return components[i].size() > components[j].size();
    });

    vector<int> ans(n, -1);
    int current_rank = 0;
    for (auto index : indices) {
        for (auto i : components[index]) {
            ans[a[current_rank].second] = i + 1;
            current_rank++;
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}

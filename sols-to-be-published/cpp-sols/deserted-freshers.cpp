#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), visited(n);
    vector<vector<int>> g(n), components(n);

    for (auto &x : a) cin >> x;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int v, int component) {
        visited[v] = true;
        components[component].push_back(v);
        for (auto &u : g[v]) {
            if (!visited[u]) {
                dfs(u, component);
            }
        }
    };

    int total_components = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, total_components);
            total_components++;
        }
    }

    vector<int> indices(n);

    iota(indices.begin(), indices.end(), 0);

    sort(indices.begin(), indices.end(),
         [&](const int i, const int j) { return a[i] > a[j]; });

    sort(components.begin(), components.begin() + total_components,
         [](const vector<int> &i, const vector<int> &j) {
             return i.size() > j.size();
         });

    int current_rank = 0;
    vector<int> assigned_vertex(n);
    for (int component = 0; component < total_components; ++component) {
        for (auto &x : components[component]) {
            assigned_vertex[indices[current_rank]] = x;
            current_rank++;
        }
    }

    for (auto &x : assigned_vertex) cout << x + 1 << ' ';

    cout << '\n';

    return 0;
}

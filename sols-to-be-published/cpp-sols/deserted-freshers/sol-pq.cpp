#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> groups;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        groups.emplace(x, i);
    }

    vector<int> ans(n, -1), visited(n, 0);
    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int component_id = 0;
    vector<int> current_component;
    current_component.reserve(n);

    function<void(int)> dfs = [&](int v) {
        current_component.push_back(v);
        visited[v] = 1;
        for (auto u : g[v])
            if (!visited[u]) dfs(u);
    };

    priority_queue<tuple<int, int, int>> ordering;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        current_component.clear();
        dfs(i);
        for (auto u : current_component)
            ordering.emplace(current_component.size(), component_id, u);
        component_id++;
    }

    while (!ordering.empty()) {
        auto &[component_size, component_number, vertex] = ordering.top();
        auto &[group_size, group_index] = groups.top();
        ans[group_index] = vertex;
        ordering.pop();
        groups.pop();
    }

    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}

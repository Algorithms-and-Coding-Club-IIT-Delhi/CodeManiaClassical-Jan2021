#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using i32 = int_fast32_t;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i32 n, m;
    std::cin >> n >> m;

    std::vector<i32> a(n), visited(n);
    std::vector<std::vector<i32>> g(n), components(n);

    for (auto &&x : a)
        std::cin >> x;

    for (i32 i = 0; i < m; ++i) {
        i32 u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::function<void(i32, i32)> dfs = [&](i32 v, i32 component) {
        visited[v] = true;
        components[component].push_back(v);
        for (auto &&u : g[v]) {
            if (!visited[u]) {
                dfs(u, component);
            }
        }
    };

    i32 total_components = 0;
    for (i32 i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, total_components);
            total_components++;
        }
    }

    std::vector<i32> indices(n);

    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(),
            [&](const i32 i, const i32 j) {
                return a[i] > a[j];
            });

    std::sort(components.begin(), components.begin() + total_components,
            [](const std::vector<i32> &i, const std::vector<i32> &j) {
                return i.size() > j.size();
            });

    i32 current_rank = 0;
    std::vector<i32> assigned_vertex(n);
    for (i32 component = 0; component < total_components; ++component) {
        for (auto &&x : components[component]) {
            assigned_vertex[indices[current_rank]] = x;
            current_rank++;
        }
    }

    for (auto &&x : assigned_vertex)
        std::cout << x + 1 << ' ';

    std::cout << '\n';

    return 0;
}

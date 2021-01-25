#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<pii> vpi;

bool desc_sort(const int& lhs, const int& rhs) { return lhs > rhs; }
bool desc_pii_sort(const pii& lhs, const pii& rhs) { return lhs > rhs; }

bool second_sort(const pii& lhs, const pii& rhs) {
    pii a, b;
    a.first = lhs.second;
    a.second = lhs.first;
    b.first = rhs.second;
    b.second = rhs.first;
    return a < b;
}

template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
    os << "[ ";
    for (auto v : V) os << v << " ";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> second) {
    os << "{ ";
    for (auto s : second) os << s << " ";
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}

template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
    os << "{ ";
    for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << "\n";
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

inline long long fast_expo(long long base, long long power,
                           long long modulo = 1e0) {
    base %= modulo;
    if (base < 0LL) base += modulo;
    long long x = base, cnt = power, ans = 1LL;
    while (cnt) {
        if (cnt & 1LL) ans = (ans * x) % modulo;
        x = (x * x) % modulo;
        cnt >>= 1LL;
    }

    return ans;
}

inline long long inv(long long base, long long modulo = 1e0) {
    return fast_expo(base, modulo - 2LL, modulo);
}

vector<int> adj[100001];
int id[100001];
int idx;
int size[100001];
int cc;
bool check[100001];

void dfs(int r) {
    id[r] = idx;
    cc++;
    check[r] = 1;
    for (auto x : adj[r]) {
        if (!check[x]) dfs(x);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    pii a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            cc = 0;
            idx = i;
            dfs(i);
            size[i] = cc;
        }
    }

    int ans[n + 1];
    sort(a + 1, a + n + 1);
    ppi city[n + 1];
    for (int i = 1; i <= n; i++) {
        city[i].first.first = size[id[i]];
        city[i].first.second = id[i];
        city[i].second = i;
    }

    sort(city + 1, city + n + 1);
    for (int i = 1; i <= n; i++) {
        ans[a[i].second] = city[i].second;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

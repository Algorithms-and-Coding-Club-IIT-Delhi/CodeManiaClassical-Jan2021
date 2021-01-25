#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
//#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
// #define int long long
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<pii> vpi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define d0(x) cout << (x) << " "
#define d1(x) cout << (x) << endl
#define d2(x, y) cout << (x) << " " << (y) << endl
#define d3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl
#define d4(a, b, c, d) \
    cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define d5(a, b, c, d, e) \
    cout << (a) << " " << (b) << " " << (c) << " " << (d) << " " << (e) << endl
#define d6(a, b, c, d, e, f)                                                   \
    cout << (a) << " " << (b) << " " << (c) << " " << (d) << " " << (e) << " " \
         << (f) << endl
bool desc_sort(const int& lhs, const int& rhs) { return lhs > rhs; }
bool desc_pii_sort(const pii& lhs, const pii& rhs) { return lhs > rhs; }
bool second_sort(const pii& lhs, const pii& rhs) {
    pii a, b;
    a.F = lhs.S;
    a.S = lhs.F;
    b.F = rhs.S;
    b.S = rhs.F;
    return a < b;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100000);
    int m = rnd.next(1, 100000);
    cout << n << " " << m << endl;
    set<int> adj[n + 1];
    for (int i = 1; i < n; i++) {
        cout << rnd.next(1, 1000) << " ";
    }
    cout << rnd.next(1, 1000) << endl;
    for (int i = 1; i <= m; i++) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        while (u == v || adj[u].find(v) != adj[u].end() ||
               adj[v].find(u) != adj[v].end()) {
            v = rnd.next(1, n);
            u = rnd.next(1, n);
        }
        adj[u].insert(v);
        adj[v].insert(u);
        cout << u << " " << v << endl;
    }
}

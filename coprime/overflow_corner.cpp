#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 20000;
    long long a = 1'410'065'427;
    cout << n << '\n';
    vector<long long> pre(n);
    long long p = 0;
    int nxt = -1;
    for (int i = 1; i < n; ++i) {
        pre[i] = min(pre[i - 1] + 1'000'000, a);
        if (pre[i] == a) {
            nxt = i + 1;
            break;
        }
    }
    long long target = 10'000'000'019LL;
    for (int i = nxt; i < n; ++i) {
        pre[i] = min(target, pre[i - 1] + 1'000'000);
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) cout << pre[0] << ' ';
        else cout << pre[i] - pre[i - 1] << " \n"[i == n - 1];
    }
}

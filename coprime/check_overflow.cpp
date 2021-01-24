#include <bits/stdc++.h>

using namespace std;

int target = 1'410'065'427;

long long final_target = 10'000'000'019LL;

int main() {
    int n;
    cin >> n;
    long long pre[n] = {0};
    long long p = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p += x;
        pre[i] = p;
        if (pre[i] == target) {
            cout << "YES\n";
        }
        if (pre[i] == final_target) {
            cout << "FINAL\n";
            return 0;
        }
    }
    return 0;
}

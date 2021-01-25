#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int maxn = 100'003;
    vector<int> dp(maxn);

    for (int i = 2; i < maxn; ++i) {
        dp[i] += i >> 1;
        int stride = i << 1;
        for (int j = 3 * i; j < maxn; j += stride) {
            dp[j] -= dp[i];
        }
    }

    int q, k, b, c, d;
    cin >> q;

    while (q--) {
        cin >> k >> b >> c >> d;
        if (k % 2 == 0)
            cout << c * dp[k + 2] << '\n';
        else
            cout << (b + d) * dp[k + 2] << '\n';
    }

    return 0;
}

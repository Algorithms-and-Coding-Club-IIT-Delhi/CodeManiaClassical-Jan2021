#include <iostream>

using namespace std;

const int MAX_N = 100'000;
const int mod = 1'000'000'007;

int dp[MAX_N][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c;
    cin >> n >> c;

    for (int i = 0; i < 10; ++i) dp[0][i] = 1;

    for (int i = 1; i < n; ++i) {
        for (int digit = 0; digit < 10; ++digit) {
            int l = max(0, digit - c), r = min(9, digit + c), &x = dp[i][digit];
            for (int j = l; j <= r; ++j) {
                x += dp[i - 1][j];
                if (x >= mod) x -= mod;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i < 10; ++i) {
        ans += dp[n - 1][i];
        if (ans >= mod) ans -= mod;
    }

    cout << ans << '\n';

    return 0;
}

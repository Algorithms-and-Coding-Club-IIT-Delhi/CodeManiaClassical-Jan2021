#include <iostream>

using i32 = int_fast32_t;

static constexpr i32 MAX_N = 100'000;
static constexpr i32 mod = 1'000'000'007;

i32 dp[MAX_N][10];

int main() {

    i32 n, c;
    std::cin >> n >> c;

    for (i32 i = 0; i < 10; ++i)
        dp[0][i] = 1;

    for (i32 i = 1; i < n; ++i)
        for (i32 digit = 0; digit < 10; ++digit) {
            i32 l = std::max(0, digit - c), r = std::min(9, digit + c),
                &x = dp[i][digit];
            for (i32 j = l; j <= r; ++j) {
                x += dp[i - 1][j];
                if (x >= mod)
                    x -= mod;
            }
        }

    i32 ans = 0;

    for (i32 i = 1; i < 10; ++i) {
        ans += dp[n - 1][i];
        if (ans >= mod)
            ans -= mod;
    }

    std::cout << ans << '\n';
}

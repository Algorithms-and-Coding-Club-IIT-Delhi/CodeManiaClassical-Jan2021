#include <iostream>
#include <vector>

using i32 = int_fast32_t;
using i64 = int_fast64_t;

const i32 MAX_P = 100'001;

i64 fact[MAX_P], ifact[MAX_P];

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    i32 n, k, p;

    std::cin >> n >> k >> p;
    
    fact[0] = 1;
    for (i32 i = 1; i < p; ++i)
        fact[i] = fact[i - 1] * i % p;
    
    ifact[p - 1] = p - 1;
    for (i32 i = p - 1; i > 0; --i)
        ifact[i - 1] = ifact[i] * i % p;
    
    i64 ans = 0;
    i32 i2, j;

    for (int i = 1; i < p; ++i) {
        i2 = (i64) i * i % p;
        j = (ifact[i2] * fact[i2 - 1] % p) * k % p;
        ans += (i64) ((n + p - i) / p) * ((n + p - j) / p);
    }
    
    std::cout << ans << '\n';

    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int iter_power(int a, int n, int p) {
    long long ans = 1;
    long long b = a;
    while (n) {
        if (n & 1)
            ans = ans * b % p;
        n >>= 1;
        b = (b * b) % p;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, p;

    cin >> n >> k >> p;

    long long ans = 0;
    int i_squared, j;

    for (int i = 1; i < p; ++i) {
        i_squared = (long long)i * i % p;
        j = (long long) (iter_power((long long) i * i % p, p - 2, p)) * k % p;
        ans += (long long)((n + p - i) / p) * ((n + p - j) / p);
    }

    cout << ans << '\n';

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int rec_power(int a, int n, int p) {
    if (n == 0) return 1;
    int x = rec_power(a, n / 2, p);
    if (n % 2 == 1) {
        return (long long) x * x % p * a % p;
    } else {
        return (long long) x * x % p;
    }
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
        j = (long long) (rec_power((long long) i * i % p, p - 2, p)) * k % p;
        ans += (long long)((n + p - i) / p) * ((n + p - j) / p);
    }

    cout << ans << '\n';

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int MAX_P = 100'001;
long long factorial[MAX_P], inverse_factorial[MAX_P];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, p;

    cin >> n >> k >> p;

    factorial[0] = 1;
    for (int i = 1; i < p; ++i) factorial[i] = factorial[i - 1] * i % p;

    inverse_factorial[p - 1] = p - 1;
    for (int i = p - 1; i > 0; --i)
        inverse_factorial[i - 1] = inverse_factorial[i] * i % p;

    long long ans = 0;
    int i_squared, j;

    for (int i = 1; i < p; ++i) {
        i_squared = (long long)i * i % p;
        j = (inverse_factorial[i_squared] * factorial[i_squared - 1] % p) * k %
            p;
        ans += (long long)((n + p - i) / p) * ((n + p - j) / p);
    }

    cout << ans << '\n';

    return 0;
}

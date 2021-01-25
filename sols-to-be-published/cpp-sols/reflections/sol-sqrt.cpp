#include <iostream>
#include <vector>

using namespace std;

int phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q, k, b, c, d;
    cin >> q;

    while (q--) {
        cin >> k >> b >> c >> d;
        if (k % 2 == 0)
            cout << c * phi(k + 2) << '\n';
        else
            cout << (b + d) * phi(k + 2) / 2 << '\n';
    }

    return 0;
}

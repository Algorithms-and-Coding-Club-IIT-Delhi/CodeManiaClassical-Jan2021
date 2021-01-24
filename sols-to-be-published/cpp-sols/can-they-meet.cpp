#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        long long a, b, x;
        cin >> a >> b >> x;

        if (a == 0 && b == 0) {
            cout << (x == 0) << '\n';
            continue;
        }

        long long g = __gcd(a, b);
        if (x % 2 == 0) {
            if ((x / 2) % g == 0) {
                cout << 1 << '\n';
                continue;
            }
        }

        x -= a + b;
        if (x % 2 == 0) {
            if ((x / 2) % g == 0) {
                cout << 1 << '\n';
                continue;
            }
        }

        cout << 0 << '\n';
    }

    return 0;
}

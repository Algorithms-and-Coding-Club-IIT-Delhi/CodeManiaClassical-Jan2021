#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int g = __gcd(a, b);
    a /= g;
    b /= g;

    if (b > 2) {
        cout << -1 << '\n';
    } else {
        if (b == 1) a *= 2;
        if (a <= 2) {
            cout << 1 << '\n'
                 << 0 << ' ' << 0 << ' '
                 << 1 << ' ' << 1 << ' '
                 << a + 2 << ' ' << 2 << '\n';
        } else {
            cout << 1 << '\n'
                 << 0 << ' ' << 0 << ' '
                 << 1 << ' ' << 2 << ' '
                 << a << ' ' << a << '\n';
        }
    }

    return 0;
}

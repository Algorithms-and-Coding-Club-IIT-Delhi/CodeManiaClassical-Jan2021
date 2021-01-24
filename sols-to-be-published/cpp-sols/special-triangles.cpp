#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned a, b;
    cin >> a >> b;
    
    auto g = __gcd(a, b);
    a /= g, b /= g;

    if (b > 2) {
        cout << -1 << endl;
        return 0;
    }

    if (b == 1)
        a *= 2;

    cout << 1 << endl;

    cout << 0 << " " << 2 * a << " "
              << 2 << " " << a << " "
              << 3 << " " << 0 << " "
              << endl;

    return 0;
}

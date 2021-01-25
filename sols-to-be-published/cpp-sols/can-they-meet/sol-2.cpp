#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;
        if (a == 0 && b == 0) {
            cout << (x == 0) << '\n';
        } else {
            cout << (x % __gcd(a + b, a - b) == 0) << '\n';
        }
    }
    return 0;
}

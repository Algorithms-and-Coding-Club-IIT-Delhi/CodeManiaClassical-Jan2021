#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q, k, b, c, d, ans = 0;
    cin >> q >> k >> b >> c >> d;

    for (int i = 0; i <= k + 2; ++i) {
        if (__gcd(i, k + 2 - i) == 1) {
            if (i % 2 == 0) {
                if ((k + 2 - i) % 2 == 0) {
                    assert(false);
                } else {
                    ans += b;
                }
            } else {
                if ((k + 2 - i) % 2 == 0) {
                    ans += d;
                } else {
                    ans += c;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int maxn = 100'003;
    vector<int> phi(maxn);
    
    for (int i = 0; i < maxn; ++i)
        phi[i] = i;
    
    for (int i = 2; i < maxn; ++i)
        if (phi[i] == i)
            for (int j = i; j < maxn; j += i)
                phi[j] -= phi[j] / i;

    int q, k, b, c, d;
    cin >> q;
    
    while (q--) {
        cin >> k >> b >> c >> d;
        if (k % 2 == 0)
            cout << c * phi[k + 2] << '\n';
        else
            cout << (b + d) * phi[k + 2] / 2 << '\n';
    }

    return 0;
}

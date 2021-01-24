#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> pre(n);

    long long p = 0;
    for (auto &x : pre) {
        cin >> x;
        p += x;
        x = p;
    }

    if (p == 1) {
        cout << -1 << endl;
        return 0;
    }

    int max_chain = 1;

    auto update = [&](long long prime) {
        int divisible = 0;
        for (auto &&x : pre) divisible += ((x % prime) == 0);
        max_chain = max(max_chain, divisible);
    };

    for (int i = 2; (long long)i * i <= p; ++i) {
        if (p % i == 0) {
            while (p % i == 0) p /= i;
            update(i);
        }
    }

    if (p > 1) update(p);

    cout << n - max_chain << endl;

    return 0;
}

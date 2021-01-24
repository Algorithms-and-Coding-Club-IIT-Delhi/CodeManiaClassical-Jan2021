#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int longest_chain(long long prime, vector<long long>& pre) {
    int divisible = 0, n = pre.size();
    for (int i = 0; i < n; ++i) {
        if (pre[i] % prime == 0) {
            divisible++;
        }
    }
    return divisible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n), pre(n);

    long long p = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p += a[i];
        pre[i] = p;
    }

    if (p == 1) {
        cout << -1 << '\n';
        return 0;
    }

    int max_chain = 1;

    for (int i = 2; (long long)i * i <= p; ++i) {
        if (p % i == 0) {
            while (p % i == 0) p /= i;
            max_chain = max(max_chain, longest_chain(i, pre));
        }
    }

    if (p > 1) max_chain = max(max_chain, longest_chain(p, pre));

    cout << n - max_chain << endl;

    return 0;
}

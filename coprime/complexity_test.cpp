#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int n = 1e5;
    const long long bigprime = 10000000019LL;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << ((long long) (i + 1) * bigprime / n - (long long) (i) * bigprime / n) << " \n"[i == n - 1];
    }
}


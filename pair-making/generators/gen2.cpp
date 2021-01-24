#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
vb isprime;

void sieve(int n) {
    isprime.assign(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isprime[i] && (ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i) isprime[j] = false;
        }
    }
}

void printv(vi v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 0);
    sieve(100000);
    vi primes;
    for (int i = 0; i < isprime.size(); i++) {
        if (isprime[i]) primes.pb(i);
    }
    int ind = primes.size() - 1;
    int p = primes[rnd.wnext(ind + 1, 1)];
    int k = rnd.next(1, p - 1);
    int n = rnd.next(p) + 1;
    cout << n << " " << k << " " << p << endl;
}

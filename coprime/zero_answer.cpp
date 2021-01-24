#include "testlib.h"
#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 1e6;

int main(int argc, char* argv[]) {
    
    registerGen(argc, argv, 1);
    
    int n = atoi(argv[1]);

    vector<int> primes = {2, 3, 5, 7, 11};
    int prime = primes[rnd.next(0, 4)];

    cout << n << '\n'; 
    for (int i = 0; i < n; ++i) {
        cout << prime * rnd.next(0, 4) << " \n"[i == n - 1];
    }

    return 0;
}

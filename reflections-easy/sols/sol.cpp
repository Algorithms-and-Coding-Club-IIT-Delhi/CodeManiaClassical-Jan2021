#include <array>
#include <iostream>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const int maxn = 100'003;
    std::array<int, maxn> phi;
    std::iota(begin(phi), end(phi), 0);
    for (int i = 2; i < maxn; ++i)
        if (phi[i] == i)
            for (int j = i; j < maxn; j += i) phi[j] -= phi[j] / i;

    int q, k, b, c, d;
    std::cin >> q;
    while (q--) {
        std::cin >> k >> b >> c >> d;
        if (k % 2 == 0)
            std::cout << c * phi[k + 2] << '\n';
        else
            std::cout << (b + d) * phi[k + 2] / 2 << '\n';
    }

    return 0;
}

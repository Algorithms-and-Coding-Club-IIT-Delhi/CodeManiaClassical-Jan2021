#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using i32 = int_fast32_t;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i32 n;

    std::cin >> n;

    i32 l = 1;
    i32 r = n;
    
    std::string result;

    while (l <= r) {
    
        i32 m = l + ((r - l) >> 1);
        
        std::cout << m << std::endl;
        std::cin >> result;
        
        if (result == "guessed") {
            exit(0);
        } else if (result == "lesser") {
            l = m + 1;
            r = m + ((r + 1 - m) >> 1);
        } else {
            l = l + ((m - l) >> 1);
            r = m - 1;
        }
    }

    assert(false);
}

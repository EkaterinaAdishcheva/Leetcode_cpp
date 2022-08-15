#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        uint32_t res = 0;
        while ( i < 32 ) {
            auto k = n & 1;
            res = res << 1;
            res = k | res;
            n =  n >> 1;

            cout << n << "\n";
            i ++ ;
        }
        cout << "\n";
        return n;
    }
};

void main() {
    uint32_t n = 00000000000000000000000000001011;
    cout << n << "\n";
    Solution solution;
    auto res = solution.reverseBits(n);
    cout << res << "\n";
}
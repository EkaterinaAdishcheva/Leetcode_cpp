#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        int digitsQnt = n;
        vector<int> availableNumbers;
        string res = "";
        for(int i = 1 ; i < n ; i ++) {
            factorial *= i;
            availableNumbers.push_back(i);
        }
        k --;
        availableNumbers.push_back(n);
        while(digitsQnt > 1) {
            int numPosition = k / factorial;
            res += char(availableNumbers[numPosition] + '0');
            availableNumbers.erase(availableNumbers.begin() + numPosition);
            k = k - numPosition * factorial;
            factorial /= (digitsQnt - 1);
            digitsQnt --;
        }
        res += char(availableNumbers[0] + '0');
        return res;
    }
};

void main() {
    int n = 3, k = 3;
    Solution solution;
    auto res = solution.getPermutation(n, k);
    cout << res << "\n";
}
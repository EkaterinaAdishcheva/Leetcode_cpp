#include <vector>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cointsQnt(amount + 1, -1);
        cointsQnt[0] = 0;
        for (int i = 1; i <= amount ; i ++ ) {
            auto qnt = -1;
            for (auto c: coins) {
                if ( i - c >= 0) {
                    if (cointsQnt[i - c] != - 1) {
                        qnt = (qnt == -1) ? cointsQnt[i - c] + 1 : min(qnt, cointsQnt[i - c] + 1);
                    }
                }
            }
            cointsQnt[i] = qnt;
        }

        return cointsQnt[amount];
    }
};
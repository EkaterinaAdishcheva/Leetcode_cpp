#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_revenue = 0;
        for (int i = 0 ; i < prices.size(); i ++ ) {
            max_revenue = max(max_revenue, prices[i] - min_price);
            min_price = min(prices[i], min_price); 
        }  
        return max_revenue;      
    }
};
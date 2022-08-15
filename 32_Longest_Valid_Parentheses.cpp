#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        map<int, int> positions;
        map<int, int>:: iterator it;
        
        int available = 0;
        int max_length = 0;
        positions[0] = -1;
        for (int i = 0 ; i < s.size(); i ++ ) {
            if (s.at(i) == ')') {
                positions[available] = INT_MAX;
                available --;
                it = positions.find(available);
                if (it != positions.end()) {
                    if ( max_length < ( i - positions[available] )) {
                            max_length = i - positions[available];
                    }
                } else {
                    positions[available] = i;
                }
            } else {
                available ++;
                positions[available] = i;
            }
        }
        return max_length;        
    }
};


void main() {
    string s = ")()";               
    Solution solution;
    auto res = solution.longestValidParentheses(s);
    cout << res << "\n";
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int currentLength = 0;
        int currentStart = -1;
        vector<int> ascii_table(128, -1);
        for(int i = 0; i < s.size(); i ++) {
            if (ascii_table[int(s[i])] > currentStart ) {
                currentStart = ascii_table[int(s[i])];
            }
            ascii_table[int(s[i])] = i;
            currentLength = i - currentStart;
            maxLength = max(maxLength, currentLength);
        }

        return  maxLength;       
    }
};


void main() {
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << "\n";
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int nuniqueS = 0, nuniqueT = 0;
        vector<int> qntS(26, 0);        
        for (int i = 0 ; i < s.size(); i ++ ) {
            if (qntS[s[i] - 'a'] == 0) {
                nuniqueS ++;
            }
            qntS[s[i] - 'a'] ++;
        }
        for (int i = 0 ; i < t.size(); i ++ ) {
            qntS[t[i] - 'a'] --;
            if (qntS[t[i] - 'a'] < 0) {
                return false;
            }
            if (qntS[t[i] - 'a'] == 0) {
                nuniqueS --;
            }
            if (nuniqueS == 0 && i != t.size() - 1) {
                return false;
            }
        }
        if (nuniqueS != 0) {
            return false;
        }
        return true;
    }
};
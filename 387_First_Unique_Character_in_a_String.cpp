#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> hash_qnt(26, 0);
        vector<int> hash_pos;

        
        for(int i = 0 ; i < s.size() ; i++) {
            hash_qnt[s[i] - 'a'] ++;
            if (hash_qnt[s[i] - 'a'] == 1) {
                hash_pos.push_back(i);
            }
        }
        
        for(int i = 0; i < hash_pos.size() ; i++)
        {
            if(hash_qnt[s[hash_pos[i]] - 'a'] == 1)
                return hash_pos[i];
        }
        
        return -1;
    }
};

void main() {
    string s = "dddccdbba";
    Solution solution;
    auto res = solution.firstUniqChar(s);
}
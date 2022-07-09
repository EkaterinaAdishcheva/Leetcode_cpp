#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res = "";
        auto continue_ind = true;
        auto position = 0;
        while (continue_ind) {
            if ( position == strs[0].length() ) {
                    continue_ind = false;
                    break;    
                }
            char l = strs[0].at(position);
            for (auto s: strs) {
                if ( position == s.length() )
                {
                    continue_ind = false;
                    break;    
                }
                if ( l != s.at(position) ) {
                    continue_ind = false;
                    break;
                }
            }
            if ( continue_ind )
            {
                position ++;
                res = res + l;
            }
        }
        return res;
    }
};

void main() {
    vector<string> strs = {""};
    Solution solution;
    auto res = solution.longestCommonPrefix(strs);
    std::cout << res << "\n";
}
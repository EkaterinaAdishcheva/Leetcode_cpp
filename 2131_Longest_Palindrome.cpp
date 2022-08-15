#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> count_words;
    
        for (auto word: words) {
            ++ count_words[word];
        }
        
        int palindrom_self_words_pairs = 0; 
        int palindrom_self_words_center = 0; 
        int pairs_qnt = 0;
        vector<string> pairs_words;
        for (auto &[word, count] : count_words) {
            if ( find(pairs_words.begin(), pairs_words.end(), word) == pairs_words.end() ) {
                if(word[0] == word[1]) {
                    palindrom_self_words_pairs += count / 2;
                    if (count % 2 == 1 && palindrom_self_words_center == 0) {
                        palindrom_self_words_center = 1;
                    }
                } else {
                    string palindrom;
                    palindrom += word[1];
                    palindrom += word[0];
                    if (count_words.find(palindrom) != count_words.end()) {
                        pairs_qnt += min(count, count_words[palindrom]);
                        pairs_words.push_back(palindrom);
                    }    
                }
            }
        }

        auto res = pairs_qnt * 2 + palindrom_self_words_pairs * 2 + palindrom_self_words_center;
        return res * 2;
    }
};

void main() {
    vector<string>  words = {"dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"};
    Solution solution;
    auto res = solution.longestPalindrome(words);
    cout << res << "\n";    
}
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> words_qnt;
        map<string, int>::iterator it;
        vector<int> res;

        int word_length = words[0].size();

        for (int w = 0; w < words.size(); w ++ ) {
            it = words_qnt.find(words[w]);
            if (it == words_qnt.end()) {
                words_qnt[words[w]] = 1;
            } else {
                words_qnt[words[w]] += 1;
            }
        }
         
        for (int i = 0; i < s.size() - words.size()*word_length + 1; i ++ ) {
            bool specific_position = true;
            map <string,int> words_qnt_current(words_qnt);
            for (int w = 0; w < words.size(); w ++ ) {
                string substring = s.substr(i+w*word_length, word_length);
                it =  words_qnt_current.find(substring);
                if (it == words_qnt_current.end()) {
                    specific_position = false;
                    break;
                }
                it->second -= 1;
                if (it->second < 0) {
                    specific_position = false;
                    break;
                }
            }
            if (specific_position) {
                res.push_back(i);
            }
        }
        return res;
    }
};


void main() {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};

    Solution solution;
    auto res = solution.findSubstring(s, words);
    for (auto r: res) {
        cout << r << "\t";
    }
    cout << "\n";
}
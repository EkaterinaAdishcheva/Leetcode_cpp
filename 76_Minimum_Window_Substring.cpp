#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    int findMinPosition(map <int, int> tLettersQnt, vector<vector<int>> asciiTableS) {
        int res = INT_MAX;
        for (auto m: tLettersQnt) {
            res = min( res, asciiTableS[m.first][0] );
        }
        return res;
    }  

public:
    string minWindow(string s, string t) {
        map <int, int> tLettersQnt;
        map <int, int>::iterator it;
        vector<vector<int>> asciiTableS(128);
        
        for (int i = 0 ; i < t.size(); i ++ ) {
            it = tLettersQnt.find(int(t[i]));
            if (it == tLettersQnt.end()) {
                tLettersQnt.insert(make_pair(int(t[i]), 1));
            } else {
                it->second ++;    
            }
        }

        int lettersQntMatched = 0;
        int minCurrentPosition = 0;
        int minLength = INT_MAX;
        int minPosition = INT_MAX;

        for (int i = 0 ; i < s.size(); i ++ ) {
            it = tLettersQnt.find(int(s[i]));
            if (it != tLettersQnt.end()) {
                asciiTableS[int(s[i])].push_back(i);
                if (asciiTableS[int(s[i])].size() ==  it->second) {
                    lettersQntMatched ++;
                    if (lettersQntMatched == tLettersQnt.size()) {
                        minCurrentPosition = findMinPosition(tLettersQnt, asciiTableS);
                        auto currentLength = i - minCurrentPosition + 1;
                        if (currentLength < minLength) {
                            minLength = currentLength;
                            minPosition = minCurrentPosition;
                        }
                    }
                } else if (asciiTableS[int(s[i])].size() >  it->second) {
                    auto minSymbolPosition = asciiTableS[int(s[i])][0];
                    asciiTableS[int(s[i])].erase(asciiTableS[int(s[i])].begin());
                    if (lettersQntMatched == tLettersQnt.size()) {

                        if (minCurrentPosition == minSymbolPosition) {
                            minCurrentPosition = findMinPosition(tLettersQnt, asciiTableS);    
                            auto currentLength = i - minCurrentPosition + 1;
                            if (currentLength < minLength) {
                                minLength = currentLength;
                                minPosition = minCurrentPosition;
                            }
                        }
                    }
                }
            }    
        }
        if (minPosition == INT_MAX) {return "";}
        return s.substr(minPosition, minLength);
    }
};

void main() {
    string s = "bba", t = "ab";

    Solution solution;
    auto res = solution.minWindow(s, t);
    cout << res << "\n";
}
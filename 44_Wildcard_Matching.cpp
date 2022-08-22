#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool checkPatternts(string s, string p) {
//        cout << "checkPatternts\t" << s << "\t" << p << "\n";
        vector<string> patterns; 
        int begin = -1;
        for (int i = 0 ; i < p.size(); i ++ ) {
            if(begin == -1 && p[i] != '?' && p[i] != '*') {
                begin = i;
            } else if(begin != -1 && ( p[i] == '?' || p[i] == '*')) {
                patterns.push_back(p.substr(begin, i - begin));
                begin = -1;
            }
        }
        if (begin != -1) {
            patterns.push_back(p.substr(begin, p.size() - begin)); 
        }
        int pos = 0, counter = 0;
        for (auto currentPattern: patterns) {
            while(pos < s.size()) {
                if (s.substr(pos, currentPattern.size()) == currentPattern ) {
                    counter ++;
                    pos += currentPattern.size();
                    break;
                }
                pos ++;
            }
        }
        if (counter == patterns.size()) {
            return true;
        }
        return false;
    }

    string shortP(string p) {
        string newP = p.substr(0, 1);
        for (int i = 1 ; i < p.size(); i ++ ) {
            if (newP[newP.size() - 1] != '*' || p[i] != '*') {
                newP += p.substr(i, 1);
            }
        }
        return newP;
    }
    bool checkIsMatch(string s, string p) {
//        cout << "checkIsMatch\t" << s << "\t" << p << "\n";

        if (s.size() < p.size()/2) {
            return false;
        }
                // remove letters
        if (p.size() > 0) {
            string pLettersLeft = "";
            int positionL = 0;
            while(p[positionL] != '?' && p[positionL] != '*')
            {
                positionL ++;
                if (positionL == p.size()) {
                    break;
                }
            }

            if (positionL > 0) {
                pLettersLeft = p.substr(0, positionL);
                if (s.size() < pLettersLeft.size() || pLettersLeft != s.substr(0, pLettersLeft.size())) {
                    return false;
                }
                p = p.substr(pLettersLeft.size(), p.size() - pLettersLeft.size());
                s = s.substr(pLettersLeft.size(), s.size() - pLettersLeft.size());
            }
        }
        if (p.size() > 0) {
            string pLettersRight = "";
            int positionR = p.size() - 1;
            while(p[positionR] != '?' && p[positionR] != '*')
            {
                positionR --;
                if (positionR == 0) {
                    break;
                }
            }
            if (positionR != p.size() - 1) {
                pLettersRight = p.substr(positionR + 1, p.size() - positionR - 1);
                if (s.size() < pLettersRight.size() || pLettersRight != s.substr(s.size() - pLettersRight.size(), pLettersRight.size())) {
                    return false;
                }
                p = p.substr(0, p.size() - pLettersRight.size());
                s = s.substr(0, s.size() - pLettersRight.size());
            }
        }
        bool checkPatterntsRes = checkPatternts(s, p); 
        if (!checkPatterntsRes) {
            return false;
        }
        if (p.size() == 0) {
            if (s.size() == 0) {
                return true;
            }
            return false;
        }

        if (p.size() == 1) {
            if ((p == "?" && s.size() == 1) || p == "*" || p == s ) {
                return true;
            }
            return false;
        }
        if ( p[0] == '?' ) {
            if (s.size() == 0) {
                return false;
            }
            return checkIsMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
        }
        if ( p[0] == '*' ) {
            if ( s.size() == 0) {
                return checkIsMatch(s, p.substr(1, p.size()-1));
            } else {
                for (int j = 0 ; j < s.size() ; j ++ ) {
                    if ( checkIsMatch(s.substr(j, s.size()-j), p.substr(1, p.size()-1)) ) {
                        return true;
                    }
                }
                return false;
            }
            return false;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        p = shortP(p);
        auto res = checkIsMatch(s, p);
        return res;
    }
};

void main() {

    string s = "aa", p = "a";
    Solution solution;
    auto res = solution.isMatch(s, p);
    cout << res << "\n";
}
#include <string>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> stackParentheses;

        map <char, char> parenthesesMap { {'(', ')'}, {'{', '}'}, {'[', ']'}, };

        for (int i = 0 ; i < s.length() ; i ++ ) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[' ) {
                stackParentheses.push(parenthesesMap[s[i]]);
            } else {
                if (!stackParentheses.empty() && s[i] == stackParentheses.top()) {
                    stackParentheses.pop();
                } else {
                    return false;
                }
            }
        }
        if ( stackParentheses.empty() ) {
            return true;
        }
        return false;
    }
};
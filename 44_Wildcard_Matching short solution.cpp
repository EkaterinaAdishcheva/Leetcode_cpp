#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    
    bool isMatch(string str, string pattern) {
        int s=0, p=0, prevstr=-1, match=-1;
        while( s<str.length() ){
            if(p<pattern.length()&&(str[s]==pattern[p]||pattern[p]=='?')){
                s++;p++;
            }
            else if(p<pattern.length() && pattern[p]=='*'){
                prevstr=p;p++;
                match=s;
            }
            else if(prevstr!=-1){
                p=prevstr+1;
                match++;s=match;
            }
            else return false;
        }
        while (p < pattern.length() && pattern[p] == '*')
            p++;
        
        return p == pattern.length();
    }
};
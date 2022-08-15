#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int  n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while (i<n && s[i]==')' && !st.empty() && s[st.top()]=='(') {
                st.pop();
                i++;
            }
            if (i<n) {
                st.push(i);
            }
        }
        if (st.empty()) {
            return n;
        }
        int ans=0, x=n;
        while(!st.empty()){
            if(st.size()==1){
                ans=max(ans,st.top());
            }
            ans=max(ans,x-st.top()-1);
            x=st.top();
            st.pop();
        }
        return ans;
    }
};
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int no = 0;
        stack<int> st;
        char prevSign = '+';
        for(int i = 0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                no = no*10 + (s[i] - '0');
            }
            if(isoper(s[i]) || i==n-1)
            {
                if(prevSign == '+')
                {
                    st.push(no);
                }
                else if(prevSign == '-')
                {
                    st.push(-no);
                }
                else if(prevSign == '*')
                {
                    int top = st.top();st.pop();
                    st.push(top*no);
                }
                else if(prevSign == '/')
                {
                    int top = st.top();st.pop();
                    st.push(top/no);
                }
                no = 0;
                prevSign = s[i];
            }
        }
        int ans = 0;
        while(st.size())
        {
            ans += st.top();st.pop();
        }
        return ans;
    }
    
    bool isoper(char c)
    {
        return c=='+' || c=='-' || c=='/' || c=='*';
    }
};

void main(){
    string s = " 3+5 / 2 ";
    Solution solution;
    auto res = solution.calculate(s);
    cout << res << "\n";
}
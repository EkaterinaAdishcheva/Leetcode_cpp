class Solution {
public:
    int findx(int x,vector<int> &pr)
    {
        if(x==pr[x])return x;
        return pr[x] = findx(pr[x],pr);
    }
    
   
    void Union(int x,int y,vector<int> &pr)
    {
        int lx = findx(x,pr);
        int ly = findx(y,pr);
        pr[ly] = lx;
    }
    
    int removeStones(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> pr(n);
        for(int i = 0;i<n;i++)
        {
            pr[i] = i;
        }
                
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(a[i][0] == a[j][0]  or a[i][1] == a[j][1])
                {
                    Union(i,j,pr);
                }
            }
        }
        
        unordered_set<int> st;
        
        for(int i = 0;i<n;i++)
        {
            int x = findx(i,pr);
            st.insert(x);
        }
        return n-st.size();
    }
};
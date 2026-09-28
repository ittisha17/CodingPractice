class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int cnt=0;
        int mx=0;
        //bool is_open=false;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            else if(s[i]==')')
            {    
                mx=max(mx,cnt);
                cnt--; 
            }
        }
        return mx;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
         dp[i][i]=true;
        
        int mx_len=1;
        int start=0;
        for(int ln=2;ln<=n;ln++)
        {
            for(int l=0;l+ln<=n;l++)
            {
                int r=l+ln-1;
                if(s[l]==s[r])
                {
                    if(ln<=3 || dp[l+1][r-1])
                    { dp[l][r]=true;
                    
                    if(ln>mx_len)
                    { mx_len=ln;
                      start=l;
                    }
                   }
                }
            }
        }
        return s.substr(start,mx_len);
    }
};
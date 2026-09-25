
bool check(int i,int j,string &s,string &p,int n,int m,vector<vector<int>>&dp)
{
    if(i==n && j==m) return true;  //both fully consumed
    if(i>n || j>m ) return false;
    if(dp[i][j]!=-1)
     return dp[i][j];
    if(s[i]==p[j] || p[j]=='?')
     {  
        dp[i][j]=check(i+1,j+1,s,p,n,m,dp);
        return check(i+1,j+1,s,p,n,m,dp);
     }
    else
    {
        if(p[j]=='*')
        {   
            dp[i][j]=check(i+1,j+1,s,p,n,m,dp) || check(i+1,j,s,p,n,m,dp) || check(i,j+1,s,p,n,m,dp);
            return (check(i+1,j+1,s,p,n,m,dp) || check(i+1,j,s,p,n,m,dp) || check(i,j+1,s,p,n,m,dp));
        }
    }
    dp[i][j]=false;
    return false;
}


class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        check(0,0,s,p,n,m,dp);
        return dp[0][0];
    }
};
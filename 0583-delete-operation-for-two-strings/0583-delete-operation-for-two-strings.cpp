

int getDist(string &word1,string&word2,int n,int m,vector<vector<int>>&dp)
{
    if(n<0 && m<0)
     return 0;
    if(n<0)
     return m+1;
    if(m<0)
     return n+1;
    if(dp[n][m]!=-1)
     return dp[n][m];
    int ans=-1;
    if(word1[n]==word2[m])
     ans =getDist(word1,word2,n-1,m-1,dp);
    else
     ans=min(1+getDist(word1,word2,n-1,m,dp),1+getDist(word1,word2,n,m-1,dp)); //minimum to deltee from either of the two
    dp[n][m]=ans;
    return ans;
}


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length()-1;
        int m=word2.length()-1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return getDist(word1,word2,n,m,dp);

    }
};
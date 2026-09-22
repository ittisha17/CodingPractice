

bool solve(int i1,int i2,string &s1,string &s2,string &s3,vector<vector<int>>&dp)
{   

    if(i1==s1.length() && i2==s2.length())
     return true;

    if(dp[i1][i2]!=-1)
     return dp[i1][i2];


    bool ans1=false,ans2=false;
    if(i1<s1.length() && s1[i1]==s3[i1+i2])
      ans1=solve(i1+1,i2,s1,s2,s3,dp) ;
        
    if(i2<s2.length() && s2[i2]==s3[i1+i2])
        ans2=solve(i1,i2+1,s1,s2,s3,dp);
    
    dp[i1][i2]= ans1||ans2;
    return dp[i1][i2];
}


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
         return false;
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
        // return dp[0][0]==1?true:false;
    }
};
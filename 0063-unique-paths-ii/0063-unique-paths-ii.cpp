class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m));

        if(mat[0][0]==1)
         dp[0][0]=0;
        else
         dp[0][0]=1;
       
        for(int i=1;i<m;i++)
        {  
            if(mat[0][i]!=1)
             dp[0][i]=dp[0][i-1];
            else
             dp[0][i]=0;
        }

        for(int i=1;i<n;i++)
        {
            if(mat[i][0]!=1) ///free space
             dp[i][0]=dp[i-1][0];
            else
             dp[i][0]=0;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==1) //obstcle
                 dp[i][j]=0;
                else
                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
                 
            }
        }
        return dp[n-1][m-1];
    }
};
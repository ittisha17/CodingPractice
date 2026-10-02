class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));

           int mx_side=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]=='1')
             {dp[i][0]=1;
              mx_side=1;
             }
            else
             dp[i][0]=0;
             
        }

        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]=='1')
             {dp[0][i]=1;
              mx_side=1;
             }
            else
             dp[0][i]=0;
             
        }

     
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
                else
                 dp[i][j]=0;
                
                mx_side=max(mx_side,dp[i][j]);
            }
        }
        return mx_side*mx_side;
    }
};
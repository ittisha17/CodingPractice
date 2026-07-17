class Solution {
  public:
    int countWays(int n, int sum) {
        // code here
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        for(int i=0;i<=sum;i++) //if 0 digits then 0 possible ways
          {dp[0][i]=0;
           if(i<=9)
            dp[1][i]=1;
           else
            dp[1][i]=0;
          }
    
        for(int i=0;i<=n;i++)
          dp[i][0]=0; //if sum is 0 then also 0 possible numbers
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            { 
                
                // dp[i][j]=dp[i][j-1]+dp[i-1][j];
                for(int dig=0;dig<=9 && dig<=j;dig++)
                {
                    dp[i][j]+=dp[i-1][j-dig];
                }
            }
        }
        return dp[n][sum]==0?-1:dp[n][sum];
    }
};
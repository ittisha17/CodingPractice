class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2));
        dp[0][0]=0; //nhi kiya rob
        dp[0][1]=nums[0]; //kar liya rob

        if(n>1)
        {  dp[1][0]=max(dp[0][0],dp[0][1]);
           dp[1][1]=nums[1];
        }
        for(int i=2;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=nums[i]+max(dp[i-2][0],dp[i-2][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);

    }
};
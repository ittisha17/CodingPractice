class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {  
            int val=INT_MAX;
            for(int k=i;k<=i+nums[i] && k<n;k++)
            {
                if(dp[k]!=-1)
                 val=min(val,dp[k]);
            }
            if(val!=INT_MAX)
             dp[i]=val+1;
        }
        return dp[0];


    }
};
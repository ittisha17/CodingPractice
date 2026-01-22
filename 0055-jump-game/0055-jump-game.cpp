class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {   
            for(int k=i;k<=i+nums[i] && k<n;k++)
             {
                if(dp[k]==true)
                 {dp[i]=true;
                 break;}
             }
        }
        return dp[0];
    }
};
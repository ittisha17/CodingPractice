
int mx_cn(int l,int r,vector<int>&nums,vector<vector<int>> &dp)
{
    if(l+1>=r) return 0;
    
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=0;
    for(int k=l+1;k<r;k++)
    {
        int lcoins=mx_cn(l,k,nums,dp);
        int rcoins=mx_cn(k,r,nums,dp);
        int cr_cns=nums[l]*nums[k]*nums[r];
        ans=max(ans,lcoins+rcoins+cr_cns);
    }
    dp[l][r]=ans;
    return ans;
}


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        // Add virtual balloons
        vector<int> arr(n + 2);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        arr[0] = 1;
        arr[n + 1] = 1;

        for (int i = 0; i < n; i++)
            arr[i + 1] = nums[i];

        return mx_cn(0, n + 1, arr,dp);
      

    }
};
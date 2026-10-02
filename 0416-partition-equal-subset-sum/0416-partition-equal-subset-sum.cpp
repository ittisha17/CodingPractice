
bool solve(int id,vector<int>&nums,int t_sum,int half_sum,vector<vector<int>>&dp)
{  

    if(id==nums.size())
     return false;
    
    if(dp[id][t_sum]!=-1)
     return dp[id][t_sum]==1?true:false;

    if(t_sum==half_sum)
     return true;

    return dp[id][t_sum]=(solve(id+1,nums,t_sum-nums[id],half_sum,dp) || solve(id+1,nums,t_sum,half_sum,dp));
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
         t_sum+=nums[i];
        int id=0;
        if(t_sum%2==1) return false;
        int half_sum=t_sum/2;
        vector<vector<int>> dp(n,vector<int>(t_sum+1,-1));
        return solve(id,nums,t_sum,half_sum,dp);
    }
};
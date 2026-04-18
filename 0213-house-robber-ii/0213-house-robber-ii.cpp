int Solve(int st,int end,vector<int>&nums,int n)
{  
    vector<pair<int,int>>dp(n); //pair 0->no tincluded 1=incldued
   
        //dp[i].first-msx loot if currrent ouse is not looted
        //dp[i].second-->> max loot if current house is looted
     dp[st].first=0;
     dp[st].second=nums[st];
     for(int i=st+1;i<end;i++)
     {
        dp[i].first=max(dp[i-1].second,dp[i-1].first); //not including current house
        dp[i].second=nums[i]+dp[i-1].first;
     }
     return max(dp[end-1].first,dp[end-1].second);
}


class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        //using hint nned to prcess for 0--n-1 and 1--n-2
        int v1=Solve(0,n-1,nums,n);
        int v2=Solve(1,n,nums,n);
        return max(v1,v2);

    }
};
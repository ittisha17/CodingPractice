
int solve(int idx,vector<int>&dp,vector<pair<int,int>>&vec,int n)
{
    if(idx==n)
     return 0;
    
    if(dp[idx]!=-1)
     return dp[idx];
    

    int next_idx=idx+1;
    if(next_idx<n && vec[next_idx].first==vec[idx].first+1)
     next_idx++;
    int ans=max(vec[idx].first*vec[idx].second+solve(next_idx,dp,vec,n),
                solve(idx+1,dp,vec,n));
    dp[idx]=ans;
    return ans;

}


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int mx_elem=nums[nums.size()-1];
        map<int,int> mp;
        for(int elem:nums)
         mp[elem]++;
        
        vector<pair<int,int>> vec;
        for(auto p:mp)
         {
            vec.push_back({p.first,p.second}); //elemnt and frequesncy;
         }
        int n=vec.size();
        vector<int> dp(n,-1);
        int idx=0;
        solve(0,dp,vec,n);
      
        return dp[0];
    }

};
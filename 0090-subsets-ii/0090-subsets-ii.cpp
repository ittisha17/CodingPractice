
void solve(int idx,vector<int>&temp,vector<vector<int>>&res,vector<int>&nums,int n)
{
    if(idx==n)
    {res.push_back(temp);
     return;
    }
    temp.push_back(nums[idx]);
    solve(idx+1,temp,res,nums,n);
    temp.pop_back();
     while(idx<n-1 && nums[idx]==nums[idx+1])
     idx++;
    solve(idx+1,temp,res,nums,n);
}


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int idx=0;
        int n=nums.size();
        vector<int> temp;
        solve(idx,temp,res,nums,n);
        return res;
    }
};
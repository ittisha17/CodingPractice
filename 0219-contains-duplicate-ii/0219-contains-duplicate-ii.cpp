class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int K) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                for(int k=0;k<mp[nums[i]].size();k++)
                {
                    if(i-mp[nums[i]][k]<=K)
                     return true;
                }
            }
           mp[nums[i]].push_back(i);
        }
        return false;
    }
};
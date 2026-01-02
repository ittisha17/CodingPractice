class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[n/2]==nums[n-1])
        return(nums[n/2]);
        else
        return nums[n/2 -1];
    }
};
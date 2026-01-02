class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int cnt_0=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
              cnt_0++;
            else
             prod=prod*nums[i];
        }
        vector<int>res(nums.size());
        if(cnt_0>1) 
        {   fill(res.begin(),res.end(),0);
            return res;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(cnt_0==1)
            {
                if(nums[i]==0) res[i]=prod;
                else res[i]=0;
            }
            else
             res[i]=prod/nums[i];
        }
         return res;
    }
};
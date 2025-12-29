class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>res(2);
       map<int,int> mp;
       for(int i=0;i<nums.size();i++)
       {
         if(mp.find(target-nums[i])!=mp.end())
          {
            res[0]=mp[target-nums[i]];
            res[1]=i;
            break;
          }
          else
           mp[nums[i]]=i;
       }
       return res;
    }
};
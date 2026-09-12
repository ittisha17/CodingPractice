class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            
            int st=i+1;
            int end=n-1;
            int target=-nums[i];
            while(st<end)
            {
               if(nums[st]+nums[end]>target)
                end--;
               else if(nums[st]+nums[end]<target)
                st++;
               else //when target reached
                {res.push_back({nums[i],nums[st],nums[end]});
                 while( st<end && nums[st]==nums[st+1] )
                   st++;
                 while(end>st && nums[end]==nums[end-1] )
                  end--;
                 st++;
                 end--;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1] )
              i++;
        }

        return res;
    }
};
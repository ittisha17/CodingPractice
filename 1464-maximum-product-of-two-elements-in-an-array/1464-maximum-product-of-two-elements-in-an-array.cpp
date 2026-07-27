class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=INT_MIN;
        int idx1=-1;
        int mx2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=mx1)
             {
                idx1=i;
                mx1=nums[i];
             }
        }

        for(int i=0;i<n;i++)
        {  
            if(i!=idx1)
              mx2=max(mx2,nums[i]);
        }

        return((mx1-1)*(mx2-1));
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ln=INT_MAX;
        int st=0;
        int i=0;
        int n=nums.size();
        int sum=0;
        while(i<n)
        {   sum+=nums[i];
            while(sum>=target)
            {   ln=min(ln,i-st+1);
                sum-=nums[st];
                st++;
            }
            i++;
        }
        return ln==INT_MAX?0:ln;
    }
};
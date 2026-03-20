class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int ln=0;
        int cnt_0=0;
        int st=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]==0)
             cnt_0++;
            if(cnt_0<=k)
              ln=max(ln,i-st+1);
            while(cnt_0>k)
            { if(nums[st]==0)
                 cnt_0--;
              st++;
            }

            i++;
        }
        return ln;
    }
};
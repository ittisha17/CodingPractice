
bool isPoss(float div,vector<int>&nums,int k)
{
    int sum=0;
    int  n=nums.size();
    for(int i= 0;i<n;i++)
     {  
        float val=float(nums[i])/div;
        sum+=ceil(val);
     }
     return sum<=k;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int n=nums.size();
        int h=nums[0];
        for(int i=0;i<n;i++)
        {
            h=max(h,nums[i]);
        }
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPoss(mid,nums,threshold))
             {
                ans=mid;
                h=mid-1;
             }
            else
             l=mid+1;             
        }
        return ans;
    }
};
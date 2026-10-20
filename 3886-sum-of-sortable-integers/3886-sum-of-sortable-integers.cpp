bool isCyclicSorted(int st,int end,vector<int>&nums)
{  
   int desc=0;
   for(int i=st;i<end;i++)
   {
    if(nums[i]>nums[i+1])
     desc++;
   }
   if(nums[end]>nums[st]) desc++;
   return desc<=1;

}


bool Check(int k,vector<int> &nums,int n)
{ 
    int prev_mx=INT_MIN;
    for(int i=0;i<=n-k;i+=k)
    {   
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int j=i;j<i+k;j++)
         {
            mn=min(mn,nums[j]);
            mx=max(mx,nums[j]); 
         }

        if(!isCyclicSorted(i,i+k-1,nums) || prev_mx>mn) //prev subarraymax>curr ka min to cant be sorted
         return false;
        prev_mx=mx;
    }   
    return true;
}

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int k=1;k<=n;k++)
        {
            if(n%k==0)
            {   vector<int> vec=nums;
                if(Check(k,vec,n))
                 ans+=k;
            }
        }
        return ans;
    }
};
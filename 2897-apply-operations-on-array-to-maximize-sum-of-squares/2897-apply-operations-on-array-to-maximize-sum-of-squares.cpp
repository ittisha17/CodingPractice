class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32,0);
        long long ans=0;
        for(int i=31;i>=0;i--)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]&(1<<i))
                 bits[i]++;
            }
        }
        long long mod=1e9+7;
        for(int i=0;i<k;i++)
        {  
            long long curr=0;
            for(int j=0;j<32;j++){
                if(bits[j]>0)
                { curr+=1<<j;
                 bits[j]--;}
            }
            ans=(ans+curr*curr%mod)%mod;
        }
        return (int)ans;
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        vector<long long> preDiff(n,0);
        vector<long long>postDiff(n,0);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            preDiff[i]=1LL*abs(nums[i]-nums[i-1])*i+preDiff[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            postDiff[i]=1LL*abs(nums[i]-nums[i+1])*(n-i-1)+postDiff[i+1];
        }

        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
          ans=min(ans,(preDiff[i]+postDiff[i]));
        }
        return (int)ans;
    }
};
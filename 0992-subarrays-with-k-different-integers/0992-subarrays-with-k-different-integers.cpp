
int atMostk(vector<int>& nums, int k)
{
    int n=nums.size();
    unordered_map<int,int> mp;
    int cnt=0;
    int st=0;
    for(int i=0;i<n;i++)
    {   mp[nums[i]]++;
        while(mp.size()>k)
         {  mp[nums[st]]--;
          if(mp[nums[st]]==0)
            mp.erase(nums[st]);
            st++;
        }
        cnt+=i-st+1;
    }
    return cnt;
 }



class Solution {
public:
int subarraysWithKDistinct(vector<int>& nums, int k) {
   int ans=atMostk(nums,k)-atMostk(nums,k-1);
   return ans;
}
};
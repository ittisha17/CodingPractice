class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int ans=INT_MIN;
        int curr=arr[0];
        for(int i=1;i<k;i++)
         curr=curr^arr[i];
        ans=curr;
        for(int i=k;i<n;i++)
        {
            curr=curr^arr[i-k]^arr[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};
class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
           if(arr[i]+i>=n-1)
            dp[i]=1;
           else
           {
             for(int j=i+1;j<=arr[i]+i;j++)
             {
                if(dp[j]==1)
              {   dp[i]=1;
                 break;
             }
             }
           }
        }
        return dp[0]==1?true:false;
    }
};
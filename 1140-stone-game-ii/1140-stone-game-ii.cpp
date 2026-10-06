int solve(int id,int M,vector<int>&piles,vector<int>&suffSum,vector<vector<int>>&dp)
{
  if(id>=piles.size())
   return 0;
 if(dp[id][M]!=-1)
  return dp[id][M];
 int mx_stones=0;
  for(int i=1;i<=2*M;i++)
  {
    int curr=suffSum[id]-solve(id+i,max(M,i),piles,suffSum,dp);
    mx_stones=max(mx_stones,curr);
  }
  dp[id][M]=mx_stones;
  return mx_stones;
}


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>suffSum(n);
        vector<vector<int>>dp(n,vector<int>(300,-1));
        suffSum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)
         suffSum[i]=piles[i]+suffSum[i+1];
        
        return solve(0,1,piles,suffSum,dp);
    }
};
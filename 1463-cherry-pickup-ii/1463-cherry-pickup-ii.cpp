

int solve(int r,int c1,int c2,vector<vector<int>>&grid,int n,int m,vector<vector<vector<int>>>&dp)
{
   if(r==n)
    return 0;
  if(dp[r][c1][c2]!=-1)
   return dp[r][c1][c2];
   vector<int>dy={1,0,-1};
   
   int curr=grid[r][c1];
   if(c1!=c2)
    curr+=grid[r][c2];
   int mx=0;
   for(int i=0;i<3;i++)
   {
    for(int j=0;j<3;j++)
     {int ny1=c1+dy[i];
      int ny2=c2+dy[j];
      if(ny1>=0 && ny1<m && ny2>=0 && ny2<m)
      mx=max(mx,solve(r+1,ny1,ny2,grid,n,m,dp));
   }
   }
   dp[r][c1][c2]=curr+mx;
      return curr+mx;


}


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        solve(0,0,m-1,grid,n,m,dp);
        return dp[0][0][m-1];

    }
};
int solve(int i,int j,vector<vector<int>>&matrix,int n,int m,int&mx_path,vector<vector<int>>&dp) //return longest inc path ending at i,j
{
    if(i>=n || j>=m)
     return 0;
    if(dp[i][j]!=-1)
     return dp[i][j];
    int mx=0;
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    for(int k=0;k<4;k++)
    { int nx=i+dx[k];
      int ny=j+dy[k];
      if(nx>=0 && ny>=0 && nx<n && ny<m)
      {
        if(matrix[nx][ny]<matrix[i][j])
        {
            mx=max(mx,solve(nx,ny,matrix,n,m,mx_path,dp));
        }
      }
    }
    mx_path=max(mx_path,1+mx);
    dp[i][j]=1+mx;
    return 1+mx;
} 


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mx_path=0;
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans=max(ans,solve(i,j,matrix,n,m,mx_path,dp));
            }
        }
        return ans;

    }
};
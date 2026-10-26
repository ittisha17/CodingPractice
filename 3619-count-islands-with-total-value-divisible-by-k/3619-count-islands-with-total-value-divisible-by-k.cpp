void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>& grid,int n,int m,long long &sum)
{
    vis[i][j]=true;
    sum+=grid[i][j];
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[i][j]!=0)
        {
            dfs(nx,ny,vis,grid,n,m,sum);
        }
    }

}

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && !vis[i][j])
                {
                    long long sum=0;
                    dfs(i,j,vis,grid,n,m,sum);
                    if(sum%k==0)
                     cnt++;
                }
            }
        }
        return cnt;
    }
};
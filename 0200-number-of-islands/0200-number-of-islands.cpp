
void dfs(int x,int y,vector<vector<bool>>&visited,vector<vector<char>>&grid,int n,int m)
{
    visited[x][y]=true;
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]=='1')
         dfs(nx,ny,visited,grid,n,m);
    }
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')//possible island
                {
                    dfs(i,j,visited,grid,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
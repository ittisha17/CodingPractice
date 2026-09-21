bool check(vector<vector<bool>>&vis,vector<vector<int>>&grid)
{
    for(int i=0;i<vis.size();i++)
    {
        for(int j=0;j<vis[0].size();j++)
        {
            if(grid[i][j]==0 && !vis[i][j])
             return false;
        }
    }
    return true;
}

void traverse(int x,int y,vector<vector<int>>&grid,int n,int m,int &ans,vector<int>&dx,vector<int>&dy,vector<vector<bool>>&vis)
{  
    if(x>=n || y>=m) return;
    vis[x][y]=true;
    if(grid[x][y]==2)
    {  
        if(check(vis,grid))
          ans++;
        vis[x][y]=false;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]!=-1)
        {
            vis[nx][ny]=true;
            traverse(nx,ny,grid,n,m,ans,dx,dy,vis);
            vis[nx][ny]=false;
        }
    }
    return;
}


class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int ans=0;
       vector<int>dx={1,-1,0,0};
       vector<int> dy={0,0,1,-1};
       vector<vector<bool>>vis(n,vector<bool>(m,false));
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
            if(grid[i][j]==1)
            {  
                // vis[i][j]=true;
                traverse(i,j,grid,n,m,ans,dx,dy,vis);
            }
         }
       }
       return ans;

    }
};
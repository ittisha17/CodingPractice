
void dfs(int x,int y,vector<vector<bool>>&vis,int n,int m,vector<vector<int>>&img)
{
    vis[x][y]=true;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    for(int i=0;i<4;i++)
    {
       int nx=x+dx[i];
       int ny=y+dy[i];
       if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && img[nx][ny]==img[x][y] )
       {
         dfs(nx,ny,vis,n,m,img);
       }
    }
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(sr,sc,vis,n,m,image);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])
                 image[i][j]=color;
            }
        }
    return image;
        
    }
};
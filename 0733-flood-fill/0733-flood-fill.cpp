
void dfs(int x,int y,int n,int m,int org,int color,vector<vector<bool>>&visited,vector<vector<int>>&image)
{
    visited[x][y]=true;
    image[x][y]=color;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==org && !visited[nx][ny])
         dfs(nx,ny,n,m,org,color,visited,image);
    }
}



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        //basically starting from the inital point where all can i reach such that it has the same value value as the initial node;
        int n=image.size();
        int m=image[0].size();
        int org=image[sr][sc];
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,org,color,visited,image);
        return image;

    }
};
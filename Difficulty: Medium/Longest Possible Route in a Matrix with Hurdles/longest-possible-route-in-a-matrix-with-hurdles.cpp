

void traverse(int x,int y,int xd,int yd,vector<vector<bool>>&visited,int n,int m,int&ans,int dst,vector<vector<int>>& mat)
{
    if(x==xd && y==yd)
    {
        ans=max(ans,dst);
        return;
    };
    vector<int>dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    for(int i=0;i<4;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && !visited[nx][ny])
      {
          visited[nx][ny]=true;
          traverse(nx,ny,xd,yd,visited,n,m,ans,dst+1,mat);
          visited[nx][ny]=false;
      }
    }
    
}


class Solution {
  public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        int ans=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[xs][ys]=true;
        traverse(xs,ys,xd,yd,visited,n,m,ans,0,mat);
        if(ans==INT_MIN)
         return -1;
        else
         return ans;
        
    }
};
class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                visited[i][0]=true;  //first col
            }
            if(grid[i][m-1]==1)
            {
                q.push({i,m-1});
                visited[i][m-1]=true; // last col
            }
            
        }
        
        for(int j=1;j<m-1;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                visited[0][j]=true;  //first row
            }
            if(grid[n-1][j]==1)
            {
                q.push({n-1,j});
                visited[n-1][j]=true; // last row
            }
        }
        
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && ny<m && nx>=0 && ny>=0 && !visited[nx][ny] && grid[nx][ny]==1)
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                 cnt++;
            }
        }
        return cnt;
        
    }
};
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                { dist[i][j]=0;
                 q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            vector<int> dx={1,-1,0,0};
            vector<int> dy={0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0 )
               {   
                 if(dist[nx][ny]>dist[x][y]+1)
                  {dist[nx][ny]=dist[x][y]+1;
                 q.push({nx,ny});
                }
               }
           }
        }
        return dist;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        if(grid[0][0]==1)
         return -1;
        dist[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> dx={0,0,1,-1,-1,-1,1,1};
        vector<int> dy={1,-1,0,0,-1,1,-1,1};
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0 ) //valid neighbour
                {
                    if(dist[nx][ny]==-1)
                     {dist[nx][ny]=dist[x][y]+1;
                      q.push({nx,ny});
                     }
                    else
                     dist[nx][ny]=min(dist[nx][ny],dist[x][y]+1);
                }
            }
        }
        return dist[n-1][m-1];
    }
};
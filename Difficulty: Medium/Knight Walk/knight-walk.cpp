class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<int> dx={-2,-2,2,2,-1,1,-1,1};
        vector<int> dy={-1,1,-1,1,2,2,-2,-2};
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        int st_x=knightPos[0]-1;
        int st_y=knightPos[1]-1;
        dist[st_x][st_y]=0;
        queue<pair<int,int>>q;
        q.push({st_x,st_y});
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
                if(nx>=0 && ny>=0 && nx<n && ny<n)
                {
                    if(dist[nx][ny]>dist[x][y]+1)
                    {
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dist[targetPos[0]-1][targetPos[1]-1]==INT_MAX?-1:dist[targetPos[0]-1][targetPos[1]-1];
    }
};
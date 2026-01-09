class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) //rotten
                 {
                    q.push({i,j});
                    vis[i][j]=true;
                 }
            }
        }
        int cnt=0;
        while(!q.empty())
        {
           int sz=q.size();
           bool flag=false;
            vector<int>dx={1,-1,0,0};
            vector<int> dy={0,0,1,-1};
            for(int k=0;k<sz;k++)
            {  auto u=q.front();
               q.pop();
               int x=u.first;
               int y=u.second;
                
            for(int i=0;i<4;i++)
              {  int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
                { 
                  vis[nx][ny]=true;
                  q.push({nx,ny});
                  flag=true;
                }
               }
            }
            if(flag) //kuch contribution kiya
           { cnt++;
            } 
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
             {
               if(grid[i][j]==1  && !vis[i][j]) return -1; }
        }    
        return cnt;
    }
};
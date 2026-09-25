class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<vector<int>> q;
        q.push({0,0,0,0});
        vis[0][0][0]=true;
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        while(!q.empty())
        {  
            vector<int> v=q.front();
            int ux=v[0];
            int uy=v[1];
            int dist=v[2];
            int k_used=v[3];
            q.pop();
            if(ux==n-1 && uy==m-1)
             return dist;
            if(k_used>k)
             continue;
            
            for(int i=0;i<4;i++)
            {
                int nx=ux+dx[i];
                int ny=uy+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {  
                    int curr_k=k_used;
                    if(grid[nx][ny]==1) //obstacle
                      curr_k++;
                    if(!vis[nx][ny][curr_k])
                        {
                            q.push({nx,ny,dist+1,curr_k});
                            vis[nx][ny][curr_k]=true;
                        }
                    
                }
            }

        }
        return -1;
        
    }
};
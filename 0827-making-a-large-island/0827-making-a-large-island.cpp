
class DSU{
    public:
     int n;
     vector<int> parent;
     vector<int>rank;
     DSU(int n)
     {
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
     }

     void unite(int u,int v)
     {
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]==rank[pv])
        {
            parent[pv]=pu;
            rank[pu]++;
        }
        else if(rank[pu]>rank[pv])
         parent[pv]=pu;
        else
         parent[pu]=pv;

     }

     int find(int x)
     {
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
     }

};


void dfs(int i,int j,int n,vector<vector<bool>>&vis,vector<vector<int>>&grid,DSU &dsu)
{
    vis[i][j]=true;
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid.size() && !vis[nx][ny] && grid[nx][ny]==1)
        {
            dsu.unite(i*n+j,nx*n+ny);
            dfs(nx,ny,n,vis,grid,dsu);
        }
    }
    
}


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 &&  !vis[i][j])
                 dfs(i,j,n,vis,grid,dsu);
            }
        }

        unordered_map<int,int> mp; //stores parent->cnt basically giving size of component
        for(int i=0;i<n*n;i++)
        {
            int p=dsu.find(i);
            mp[p]++;
        }

        //now for every 0 check which off the neighbouring gives max size
        int mx=0;
        vector<int>dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        bool found_0=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(grid[i][j]==0)
                { found_0=true;
                    int curr_sz=0;
                  set<int> parent_incl;
                  for(int k=0;k<4;k++)
                  {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    int idx=nx*n+ny;
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1)
                     {  
                        int par=dsu.find(idx);
                        if(parent_incl.find(par)==parent_incl.end())
                         {curr_sz+=mp[par];
                         parent_incl.insert(par);
                     }
                     }  
                  }
                  mx=max(mx,curr_sz+1);
                }

            }
        }
        if(!found_0) return n*n;
  return mx;


    }
};
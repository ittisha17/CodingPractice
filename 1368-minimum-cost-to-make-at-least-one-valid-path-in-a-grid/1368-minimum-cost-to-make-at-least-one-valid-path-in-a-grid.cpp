struct myCmp
{
    bool operator()(pair<pair<int,int>,int>&p1,pair<pair<int,int>,int>&p2)
    {
        return p1.second>p2.second;
    }
};


class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,myCmp> pq;
        dist[0][0]=0;
        pq.push({{0,0},0});
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();

            auto pu=p.first;
            int ux=pu.first;
            int uy=pu.second;
            int d=p.second;

            if(d>dist[ux][uy])
             continue;
            
            int nx=0,ny=0;
            if(grid[ux][uy]==1) 
             {
                nx=ux;
                ny=uy+1;
             }
            else if(grid[ux][uy]==2)
            {  nx=ux;
               ny=uy-1;    
            }
             else if(grid[ux][uy]==3)
            {
               nx=ux+1;
               ny=uy; 
            }
            else//4
            {
               nx=ux-1;
               ny=uy;
            }

            for(int i=0;i<4;i++)
            {
                int vx=ux+dx[i];
                int vy=uy+dy[i];
                if(vx>=0 && vx<n && vy>=0 && vy<m)
                {
                    if(vx==nx && vy==ny)
                    {
                        if(dist[vx][vy]>dist[ux][uy])
                         {dist[vx][vy]=dist[ux][uy];
                          pq.push({{vx,vy},dist[vx][vy]});
                         }
                    }
                    else
                    {
                        if(dist[vx][vy]>dist[ux][uy]+1)
                         {dist[vx][vy]=dist[ux][uy]+1;
                          pq.push({{vx,vy},dist[vx][vy]});
                         }
                    }

                    
                }
            }

        }
        return dist[n-1][m-1];
    }
};
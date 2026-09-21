struct myCmp{
    bool operator()(pair<pair<int,int>,int>&p1,pair<pair<int,int>,int>&p2)
    {
        return p1.second<p2.second;
    }
};


class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int t=0;
        int n=grid.size();
        vector<vector<int>> time_taken(n,vector<int>(n,INT_MAX));
        time_taken[0][0]=grid[0][0];
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,myCmp> pq;
        pq.push({{0,0},time_taken[0][0]});
        
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};

        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            auto pu=p.first;
            int u_x=pu.first;
            int u_y=pu.second;
            int t=p.second;
            if(t>time_taken[u_x][u_y])
             continue;
            
            for(int i=0;i<4;i++)
            {
                int new_x=u_x+dx[i];
                int new_y=u_y+dy[i];
                if(new_x<n && new_y<n && new_x>=0 && new_y>=0)
                {
                    if(time_taken[new_x][new_y]>max(t,grid[new_x][new_y]))
                     {
                        time_taken[new_x][new_y]=max(t,grid[new_x][new_y]);
                        pq.push({{new_x,new_y},time_taken[new_x][new_y]});
                     }
                }
            }
        }
        return time_taken[n-1][n-1];

        
    }
};
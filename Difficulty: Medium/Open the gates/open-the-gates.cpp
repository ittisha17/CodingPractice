

bool start_check(int x,int y,int idx,vector<vector<char>>&map,string&s,int n,int m, vector<vector<bool>> &visited)
{
    if(idx==s.length())
     return true;
    
    vector<int>dx={1,-1,0,0,-1,-1,1,1};
    vector<int>dy={0,0,1,-1,-1,1,-1,1};
    
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && s[idx]==map[nx][ny])
        {
            visited[nx][ny]=true;
            if(start_check(nx,ny,idx+1,map,s,n,m,visited))
             return true;
            visited[nx][ny]=false;
        }
    }
    return false;
}


bool check(vector<vector<char>>&map,string &s)
{
    int n=map.size();
    int m=map[0].size();
    int x=-1;
    int y=-1;
    int idx=0;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==s[0])
             {
                 x=i;
                 y=j;
                 visited[x][y]=true;
                 if(start_check(x,y,1,map,s,n,m,visited))
                    return true;
                 visited[x][y]=false;
             }
        }
    }
    return false;
}



class Solution {
  public:
    vector<string> openGates(vector<vector<char> >& map, vector<string>& gate_names) {
        // Code here
        set<string> gate(gate_names.begin(),gate_names.end());
        
        vector<string> res;
        for(auto s:gate)
        {
            string gate_name=s;
            if(check(map,gate_name))
              res.push_back(gate_name);
        }
        return res;
        
    }
};
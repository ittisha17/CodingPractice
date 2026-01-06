

void find(int x,int y,string&curr,vector<string>&res,int n,vector<vector<int>>&maze,vector<vector<bool>>&visited)
{  
    if(x==n-1 && y==n-1)
      { res.push_back(curr);
        return; }
    vector<int> dx={1,0,0,-1};
    vector<int> dy={0,-1,1,0};
    vector<char> dir={'D','L','R','U'};
    for(int i=0;i<4;i++)
    {   int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<n && maze[nx][ny]==1 && !visited[nx][ny])
        {
            visited[nx][ny]=true;
            curr+=dir[i];
            find(nx,ny,curr,res,n,maze,visited);
            visited[nx][ny]=false;
            curr.pop_back();
        }
    }
    return;
}


class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n=maze.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        if(maze[0][0]==0) return res;
        visited[0][0]=true;
        string curr="";
        find(0,0,curr,res,n,maze,visited);
        return res;
        
    }
};
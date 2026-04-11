void dfs(int i,int n,vector<vector<int>>& isConnected,vector<bool>&visited)
{
    visited[i]=true;
    for(int j=0;j<n;j++)
    {
       if(j!=i && isConnected[i][j]==1 && !visited[j])
         dfs(j,n,isConnected,visited);
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
             { 
               dfs(i,n,isConnected,visited); 
               cnt++;
             }
        }
        return cnt;
    }
};
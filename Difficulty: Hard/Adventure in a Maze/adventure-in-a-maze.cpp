


class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int mod=1e9+7;
        vector<vector<long long>> ways(n,vector<long long>(n,0));
        vector<vector<long long>> sum(n,vector<long long>(n,0));
        ways[0][0]=1;
        sum[0][0]=grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                     if(i-1>=0) //top
                      {if(grid[i-1][j]==2 || grid[i-1][j]==3 && ways[i-1][j]>0)
                         {ways[i][j]=(ways[i-1][j]+ways[i][j])%mod;
                         sum[i][j]=max(sum[i][j],sum[i-1][j]+grid[i][j]);}
                         }
                      
                      if(j-1>=0)
                      {
                          if(grid[i][j-1]==1 || grid[i][j-1]==3 && ways[i][j-1]>0)
                          {
                              ways[i][j]=(ways[i][j-1]+ways[i][j])%mod;
                              sum[i][j]=max(sum[i][j],sum[i][j-1]+grid[i][j]);
                          }
                      }
                         
          }
        }
        if(ways[n-1][n-1]==0)
         return{0,0};
        return {ways[n-1][n-1],sum[n-1][n-1]};
        
        
    }
};
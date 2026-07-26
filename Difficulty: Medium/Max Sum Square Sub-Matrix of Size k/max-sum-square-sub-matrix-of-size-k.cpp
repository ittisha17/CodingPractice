class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pre_sum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pre_sum[i][j]=mat[i-1][j-1]+pre_sum[i-1][j]+pre_sum[i][j-1]-pre_sum[i-1][j-1];
            }
        }
        
        
        int ans=INT_MIN;
        for( int i=1;i<=n-k+1;i++)
        {
            for(int j=1;j<=m-k+1;j++)
            {
                int subGridsum=pre_sum[i+k-1][j+k-1]-pre_sum[i-1][j+k-1]-pre_sum[i+k-1][j-1]+pre_sum[i-1][j-1];
                ans=max(ans,subGridsum);
            }
        }
        return ans;
        
        
        
    }
};
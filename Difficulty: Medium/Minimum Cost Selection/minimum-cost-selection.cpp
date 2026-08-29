class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> res(n,vector<int>(3));
        res[0][0]=mat[0][0];
        res[0][1]=mat[0][1];
        res[0][2]=mat[0][2];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                 res[i][j]=mat[i][j]+min(res[i-1][1],res[i-1][2]);
                else if (j==1)
                 res[i][j]=mat[i][j]+min(res[i-1][0],res[i-1][2]);
                else
                 res[i][j]=mat[i][j]+min(res[i-1][0],res[i-1][1]);
            }
        }
        
        int ans=min(res[n-1][0],min(res[n-1][1],res[n-1][2]));
        return ans;
        
        
    }
};
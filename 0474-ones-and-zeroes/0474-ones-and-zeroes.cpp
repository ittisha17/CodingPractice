int getMaxSize(int idx,vector<pair<int,int>> &vec,int m,int n,int ln,vector<vector<vector<int>>> &dp)
{
      if(idx==ln) return 0;
      if(m<=0 && n<=0)
       return 0;
      if(dp[idx][m][n]!=-1)
        return dp[idx][m][n];
      
      int take=INT_MIN;

      if(vec[idx].first<=m && vec[idx].second<=n)
       take=1+getMaxSize(idx+1,vec,m-vec[idx].first,n-vec[idx].second,ln,dp);
      int not_take=getMaxSize(idx+1,vec,m,n,ln,dp);

      int ans=max(take,not_take);
      dp[idx][m][n]=ans;
      return ans;
      
       

}


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ln=strs.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<ln;i++)
        {
            int cnt_0=0;
            int cnt_1=0;
            for(char ch:strs[i])
            {
                if(ch=='0')
                 cnt_0++;
                else
                 cnt_1++;
            }
            vec.push_back({cnt_0,cnt_1});
        }

        vector<vector<vector<int>>> dp(ln,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int idx=0;
        getMaxSize(0,vec,m,n,ln,dp);
        return dp[0][m][n];

    }
};
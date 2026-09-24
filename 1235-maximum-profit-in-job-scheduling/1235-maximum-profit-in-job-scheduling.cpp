class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {   
        int n=startTime.size();
        vector<vector<int>> job(n,vector<int>(3));
        for(int i=0;i<n;i++)
        {
            // pair<int,int> p={};
            job[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(startTime.begin(),startTime.end());
        sort(job.begin(),job.end());
        vector<int> dp(n); //stores max profit one can make by doing job i
        dp[n-1]=job[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
            int nxt_idx=lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
            
            if(nxt_idx==n)
             dp[i]=max(job[i][2],dp[i+1]); //not taking current;
            else //
             dp[i]=max(dp[i+1],job[i][2]+dp[nxt_idx]); //maximum o fnot taking and taking
        }
        int ans=0;
        for(int i=0;i<n;i++)
         ans=max(ans,dp[i]);
        return ans;


        
    }
};
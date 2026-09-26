int max_value_stone(int turn,int id,int n,vector<int> &stone,vector<int>&dp)
{
    if(id>=n) return 0;
    int a1,a2,a3;
    a1=a2=a3=INT_MIN;
    if(dp[id]!=-1) return dp[id];
    a1=stone[id]-max_value_stone(turn^1,id+1,n,stone,dp);
    if(id+1<n)
     a2=stone[id]+stone[id+1]-max_value_stone(turn^1,id+2,n,stone,dp);
    if(id+1<n-1)
     a3=stone[id]+stone[id+1]+stone[id+2]-max_value_stone(turn^1,id+3,n,stone,dp);

    int curr_max=max(a1,max(a2,a3));
    dp[id]=curr_max;
    return curr_max;
     
}


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int turn=1; //1 for alice 0->bob
        int mx1=INT_MIN; //alice
        int mx0=INT_MIN; //bob
        int id=0;
        vector<int> dp(n,-1);
        int diff=max_value_stone(turn,id,n,stoneValue,dp);
        if(diff==0)
         return "Tie";
        else if(diff>0)
         return "Alice";
        else
         return "Bob";
    }
};
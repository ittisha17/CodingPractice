

bool check(int i,int j,string&s,string&p,vector<vector<int>>&dp)
{
    if(i==-1 && j==-1) //fully consumed both string 
     return true;

    if(j==-1) return false; //pattern consumed
    
    if(i==-1)
     {
        //rem string is removable through *x pairs?
        if(j>=1 && p[j]=='*')
        {
            return check(i,j-2,s,p,dp);
        }
        return false;
     }

    int id1=i+1;
    int id2=j+1;
    if(dp[id1][id2]!=-1)
     return dp[id1][id2];

    if(s[i]==p[j] || p[j]=='.')
    { dp[id1][id2]=check(i-1,j-1,s,p,dp);
     return dp[id1][id2];
    }
    else
    {
        if(p[j]=='*')
         {//for zero occurences check(i,j-2);
          //one or more check(i-1,j)
          bool a1=check(i,j-2,s,p,dp);
          bool a2=false;
          if(s[i]==p[j-1] || p[j-1]=='.')
           a2=check(i-1,j,s,p,dp);
          dp[id1][id2]=a1 || a2;
          return a1 || a2;
         }
    }
    dp[id1][id2]=false;
    return false;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=s.length()-1;
        int j=p.length()-1;
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return check(i,j,s,p,dp);
        return dp[0][0];
    }
};
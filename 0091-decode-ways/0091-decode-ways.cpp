class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n);
        if(s[0]>='1' && s[0]<='9')
         dp[0]=1;
        else
         dp[0]=0;
        if(n>1)
        {    
            if(s[1]>='1' && s[1]<='9')
             {  
                int val=(s[0]-'0')*10+s[1]-'0';
                if(val>=11 && val<=26)
                  dp[1]=dp[0]+1;
                else
                 dp[1]=dp[0];
             }
            else
             {
                if((s[0]-'0')*10>=10 && (s[0]-'0')*10<=26)
                 dp[1]=1;
                else
                 return 0;
             }
        }
        
        int prev_val;
        for(int i=2;i<n;i++)
        {   
            if(s[i]=='0')
            {
                   prev_val=(s[i-1]-'0')*10;
                   if(prev_val>=10 && prev_val<=26)
                    dp[i]=dp[i-2];
                   else
                    return 0;
            }
            
            if(s[i]=='0')
              dp[i]=dp[i-2];
            else
            {
                dp[i]=dp[i-1];
                if(s[i-1]!='0')
                {
                     prev_val=(s[i-1]-'0')*10+s[i]-'0';
                     if(prev_val>=11 && prev_val<=26)
                      dp[i]+=dp[i-2];
                }
            }
        }
        return dp[n-1];
    }
};
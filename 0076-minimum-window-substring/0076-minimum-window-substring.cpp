class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        int start=0;
        int i=0;
        int j=0;
        int upd_st;
        int ln=INT_MAX;
        unordered_map<char,int> mp;
        unordered_map<char,int> org_mp;
        for(int i=0;i<n;i++)
          {mp[t[i]]++;
           org_mp[t[i]]++;
          }

        while(i<m)
        {   

            if(mp.find(s[i])!=mp.end()) //character of t
            {
                if(mp[s[i]]>0)
                  j++;
                mp[s[i]]--;
            }
            while(j==n)
            {   
                int curr_len=i-start+1;
                if(curr_len<ln)
                {
                    ln=curr_len;
                    upd_st=start;
                }
                if(mp.find(s[start])!=mp.end())
                {
                    mp[s[start]]++;
                    if(mp[s[start]]>0)
                     j--;
                } //shrink window
                start++;
            }
            i++;
        }
        if(ln==INT_MAX)
         return "";
        else
         return(s.substr(upd_st,ln));

    }
};
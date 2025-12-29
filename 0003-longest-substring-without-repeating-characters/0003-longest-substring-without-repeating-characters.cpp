class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        int end=0;
        int n=s.length();
        set<char> visited;
        int i=0;
        int ln=0;
        while(i<n)
        {
            if(visited.find(s[i])!=visited.end()) //not ditinct
            {
               ln=max(ln,i-st);
               while(st<i && s[st]!=s[i])
                {  visited.erase(s[st]);
                    st++;
                }
                visited.erase(s[st]);
                st++;
            }
            else
            {
                visited.insert(s[i]);
                i++;
            }
        }
          ln = max(ln, n - st); //last windpow
        return ln;
        
    }
};
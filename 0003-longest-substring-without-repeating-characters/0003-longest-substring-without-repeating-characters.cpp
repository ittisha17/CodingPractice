class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int start=0;
        set<int>st;
        int n=s.length();
        int ln=0;
        while(i<n)
        { 
           while(st.find(s[i])!=st.end())
            {
                st.erase(s[start]);
                start++;
            }
            st.insert(s[i]);
            ln=max(ln,i-start+1); 
            i++;
        }
        return ln;
    }
};
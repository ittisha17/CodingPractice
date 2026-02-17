class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int n=s.length();
        int i=0;
        set<char> st;
        int ln=0;
        while(i<n)
        {
            if(st.find(s[i])!=st.end()) //if already appeared
            {  
                ln=max(ln,i-start);
                while(st.find(s[i])!=st.end())
                {
                    st.erase(s[start]);
                    start++;
                }
            }
            st.insert(s[i]);
            i++;
        }
        ln=max(ln,n-start);
        return ln;
    }
};
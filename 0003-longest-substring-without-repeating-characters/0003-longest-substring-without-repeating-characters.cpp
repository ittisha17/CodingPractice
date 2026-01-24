class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int i=0;
        //int end;
        //if(s==" ") return 1;
        int n=s.length();
        int ln=0;
        set<char> st;
        while(i<n)
        { 
            if(st.find(s[i])!=st.end()) //duplicate character
            {
                ln=max(i-start,ln);
                while(st.find(s[i])!=st.end())
                {
                    st.erase(s[start]);
                    start++;
                }
            }
            st.insert(s[i]);
            i++;
              
        }
        ln=max(n-start,ln);
        return ln;
    }
};
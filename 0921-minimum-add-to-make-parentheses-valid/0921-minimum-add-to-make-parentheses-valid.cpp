class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        if(s=="") return 0;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
             st.push(i);
            else
            {
                if(st.empty())
                 cnt++;
                else
                 st.pop();
            }
        }
        cnt+=st.size();
        return cnt;
    }
};
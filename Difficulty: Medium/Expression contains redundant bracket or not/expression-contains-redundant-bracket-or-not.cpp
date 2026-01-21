bool isOp(char ch)
{
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

class Solution {
  public:
    
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(!isOp(st.top())) return true;
                else
                {
                    while(!st.empty() && st.top()!='(')
                     st.pop();
                    st.pop();
                }
            }
            else if (s[i]=='(' || isOp(s[i]))
             st.push(s[i]);
        }
        return false;
    }
};

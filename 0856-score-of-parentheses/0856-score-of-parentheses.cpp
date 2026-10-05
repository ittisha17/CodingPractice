class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        int score=0;
        stack<pair<bool,int>> st; //stores if the curr one is nested or not
        for(int i=0;i<n;i++)
        {
          if(s[i]=='(')
          {
            if(i<n-1 &&  s[i+1]=='(')
             st.push({true,0});
            else
             st.push({false,0});
          }
          else
          { 
            int sc=0;
            while(!st.empty() && st.top().second>0)
            {
                sc+=st.top().second;
                st.pop();
            }
            bool is_nested=st.top().first;
            st.pop();
            if(is_nested)
             sc*=2;
            else
             sc++;
            st.push({is_nested,sc});  
          }


        }

        int ans=0;
        while(!st.empty())
        {
            ans+=st.top().second;
            st.pop();
        }
        return ans;
    }
};
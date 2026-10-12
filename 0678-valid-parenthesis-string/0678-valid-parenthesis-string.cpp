class Solution {
public:
    bool checkValidString(string s) {
        vector<int> star;
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
             st.push(i);
            else if(s[i]=='*')
             star.push_back(i);
            else
            {
                if(st.empty() && star.size()==0)
                 return false;
                else if(!st.empty())
                 st.pop();
                else
                 star.pop_back();
            }
        }
        if(!st.empty() && st.size()>star.size())
         return false;

        int sz=star.size();
        while(!st.empty())
        {
            int open_id=st.top();
            int star_id=star[sz-1];
            if(star_id>open_id)
             {
                st.pop();
                sz--;
             }
            else
             return false;
        }
        return true;
    }
};
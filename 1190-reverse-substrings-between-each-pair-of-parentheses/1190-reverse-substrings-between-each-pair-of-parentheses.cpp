void reverse_s(string &s)
{
    int i=0;
    int j=s.length()-1;
    while(i<=j)
     {swap(s[i],s[j]);
     i++;
     j--;}
}


class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for(int i=0;i<s.length();i++)
        {  
            string temp="";
            if(s[i]!=')')
             { 
                st.push(s[i]+temp);
             }
            else
            {
                // string temp="";
                while(!st.empty() && st.top()!="(")
                {   
                    string top=st.top();
                    reverse_s(top);
                    temp=temp+top;
                    st.pop();
                }
                st.pop();
                st.push(temp);
            }

        }

        string res="";
        if(st.size()==1)
         return st.top();
        while(!st.empty()) 
        {
            string top=st.top();
            //reverse_s(top);
            res=top+res;
            st.pop(); 
        }
        //reverse_s(res);
        return res;
    }
};
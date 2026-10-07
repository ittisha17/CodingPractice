void solve(int id,int open,int close,int extra_open,int extra_closed,string &s,string &curr,set<string>& res)
{  
    if(id==s.length())
     {
        if(extra_open==0 && extra_closed==0)
        {res.insert(curr);
        
        }
        return;
     }
    
    if(s[id]=='(') //two choice keep or delte
    {  
        curr+='(';
        solve(id+1,open+1,close,extra_open,extra_closed,s,curr,res);
        curr.pop_back();
        if(extra_open>0)
         solve(id+1,open,close,extra_open-1,extra_closed,s,curr,res);
    }
    else if(s[id]==')')
    {
      
      if(close<open)
      {
        curr+=')';
         solve(id+1,open,close+1,extra_open,extra_closed,s,curr,res);
        curr.pop_back();
      }
      if(extra_closed>0) 
         solve(id+1,open,close,extra_open,extra_closed-1,s,curr,res);

      
    }
    else //letters
    {
        curr+=s[id];
        solve(id+1,open,close,extra_open,extra_closed,s,curr,res);
        curr.pop_back();
    }

}

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> res;
        int n=s.length();
        //vector<int> pos;
        stack<int> st;
        int extra_closed=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            { st.push(i);
            }
            else if(s[i]==')')
            {  
                
                if(st.empty())
                { 
                 extra_closed++;
                }
                else
                 st.pop();
            }
        }

        int extra_open=st.size();
        int open=0;
        int closed=0;
        string curr="";
        solve(0,open,closed,extra_open,extra_closed,s,curr,res);

        vector<string> ans;
        for(auto sc:res)
         ans.push_back(sc);
        return ans;
        



        
    }
};
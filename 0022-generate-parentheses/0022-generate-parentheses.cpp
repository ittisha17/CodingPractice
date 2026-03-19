

void solve(int open,int closed,vector<string>&res,string &curr,int n)
{  
    if(curr.length()==2*n)
     res.push_back(curr);
    if(open<n)
     {
        curr+="(";
        solve(open+1,closed,res,curr,n);
        curr.pop_back();
     }
    if(open>closed)
    {
        curr+=")";
        solve(open,closed+1,res,curr,n);
        curr.pop_back();
    }
     
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=0;
        int closed=0;
        vector<string> res;
        string curr="";
        solve(open,closed,res,curr,n);
        return res;
    }
};
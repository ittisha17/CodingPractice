
bool isPali(string &s,int l,int r)
{
    while(l<=r)
    {
        if(s[l]!=s[r])
         return false;
        l++;
        r--;
    }
    return true;
}

void Solve(int idx,string &s,vector<vector<string>>&res,vector<string>&temp)
{   
    if(idx==s.length())
    { res.push_back(temp);
      return;
    }

    for(int j=idx;j<s.length();j++)
    if(isPali(s,idx,j))
    { temp.push_back(s.substr(idx,j-idx+1));
      Solve(j+1,s,res,temp);
      temp.pop_back();
    }
       
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int idx=0;
        int ln=s.length();
        Solve(idx,s,res,temp);
        return res;

    }
};
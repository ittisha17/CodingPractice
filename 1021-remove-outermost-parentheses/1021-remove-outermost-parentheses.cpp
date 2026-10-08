class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        set<int>pos;
        int st=0;
        pos.insert(st);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
             cnt++;
            else
             {
                cnt--;
                if(cnt==0)
                { pos.insert(i);
                  st=i+1;
                  pos.insert(st);
                }

             }    
        }
        string res="";
        for(int i=0;i<n;i++)
        {
            if(pos.find(i)==pos.end())
              res+=s[i];
        }
        return res;
    }
};
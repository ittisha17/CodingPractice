class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        string res="";
        queue<char> q;
        q.push(s[0]);
        map<char,int> mp;
 
        for(int i=0;i<s.length();i++)
        {   
            mp[s[i]]++;
            q.push(s[i]);
            
            while(!q.empty() && mp[q.front()]>1)
             q.pop();
            if(q.empty())
             res+='#';
            else
             res+=q.front();
          
        }
        return res;
        
        
    }
};
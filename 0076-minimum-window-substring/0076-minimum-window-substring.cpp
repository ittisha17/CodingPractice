
bool isPossible(vector<int>&curr_freq,vector<int>&req_freq)
{
    for(int i=0;i<256;i++)
    {
        if(curr_freq[i]<req_freq[i])
         return false;
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        set<char> req_char;
        vector<int> req_freq(256,0);
        vector<int> curr_freq(256,0);

        for(auto ch:t)
         { req_char.insert(ch);
           req_freq[ch]++;
         }
         
         int n=s.length();
         int i=0;
         int st=0;
         int match_char_cnt=0;
         int ln=INT_MAX;
         int st_idx=st;
         set<char> matched;
         while(i<n)
         { 
           curr_freq[s[i]]++;
           if(req_char.find(s[i])!=req_char.end()) //char of t
            matched.insert(s[i]);
           if(matched.size()==req_char.size()) //all characters matched
           {
             while(st<=i && isPossible(curr_freq,req_freq))
             {  
                int curr_ln=i-st+1;
                if(curr_ln<ln)
                {
                    ln=curr_ln;
                    st_idx=st;
                }
               curr_freq[s[st]]=max(curr_freq[s[st]]-1,0);
               if(curr_freq[s[st]]==0)
                matched.erase(s[st]);
               st++;
             }
           }
           i++;
           
         }
         if(ln==INT_MAX)
          return "";
         return s.substr(st_idx,ln);;

        
    }
};
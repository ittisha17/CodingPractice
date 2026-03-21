

bool valid(vector<int>&curr_freq,vector<int>&req_freq,set<char>&st)
{
    for(auto x:st)
    {
        if(curr_freq[x]<req_freq[x])
         return false;
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<int> curr_freq(256,0);
        vector<int> req_freq(256,0);
        set<char> st;
        for(int i=0;i<n;i++)
        {
            req_freq[t[i]]++;
            st.insert(t[i]);
        }
        int ln=INT_MAX;
        int start=0;
        int i=0;
        set<char> matched;
        int idx=-1;
        while(i<m)
        {   
            curr_freq[s[i]]++;
            if(st.find(s[i])!=st.end()) //character of t
             matched.insert(s[i]);
            while(matched.size() == st.size() && valid(curr_freq,req_freq,st) )  //all characters found
            {       
                    int cur_len=i-start+1;
                    if(cur_len<ln)
                    {
                        ln=cur_len;
                        idx=start;
                    }
                    curr_freq[s[start]]--;
                    if(curr_freq[s[start]]==0 && st.find(s[start])!=st.end()) //character of t and not  anymore in curr window
                    matched.erase(s[start]);
                    //ch_matched--;
                    start++;
            }
            i++;
        }
        if(idx==-1)
         return "";
        else
         return s.substr(idx,ln);
        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end());
    string res="";
    int n=strs.size();
    if(strs.size()==1) return strs[0];
    string s1=strs[0];
    string s2=strs[n-1];
    int i=0;
    while(i<s1.length())
    {
      if(s1[i]==s2[i])
       { res+=s1[i];
         i++;
       }
       else
        break;
        
    }
    return res;
    }
};
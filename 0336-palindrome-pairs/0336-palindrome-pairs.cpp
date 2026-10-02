bool isPal(string &s)
{
    int i=0;
    int j=s.length()-1;

    while(i<=j)
    {
        if(s[i]==s[j])
         {
            i++;
            j--;
         }
        else 
         return false;
    }
    return true;

}


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> mp;
        int n=words.size();
        
        for (int i = 0; i < n; i++) {
            mp[words[i]] = i;
        }

        for(int i=0;i<n;i++)
        {
            string w=words[i];
            for(int k=0;k<=w.length();k++)
            {  
                string left="",right="";
                left=w.substr(0,k);
                right=w.substr(k);
                if(k!=0 && isPal(left))
                {  
                    string rev_r=right;
                     reverse(rev_r.begin(),rev_r.end());
                    if(mp.find(rev_r)!=mp.end() && mp[rev_r]!=i)
                     res.push_back({mp[rev_r],i});
                }
                if(isPal(right))
                {
                     string rev_l=left;
                     reverse(rev_l.begin(),rev_l.end());
                    if(mp.find(rev_l)!=mp.end() && mp[rev_l]!=i)
                     res.push_back({i,mp[rev_l]});
                }

            }

        }
        return res;
    }
};
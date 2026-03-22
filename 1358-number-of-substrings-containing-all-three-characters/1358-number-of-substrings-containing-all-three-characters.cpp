
bool isValid(vector<int>&freq)
{
    for (int x:freq)
     if(x<=0)
      return false;
    return true;
}
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> freq(3,0);
        int j=0;
        int i=0;
        int cnt=0;
        while(i<n)
        {  
            freq[s[i]-'a']++;
            while(isValid(freq))
             {cnt+=n-i;
              freq[s[j]-'a']--;
              j++;
             }
             i++;
        }
        return cnt;
    }
};

 int AtMostK(string& s, int k) {  //this code 
        // code here
        if(k==0) return 0;
        int cnt=0;
        int st=0;
        int i=0;
        int n=s.length();
        vector<int> freq(26,0);
        int dist=0;
        // unordered_map<char,int> mp;
        while(i<n)
        {  
            int id=s[i]-'a';
            if(freq[id]==0)  //if distinct
             dist++;
            freq[id]++;
            while(dist>k)
            {
                freq[s[st]-'a']--;
                if(freq[s[st]-'a']==0)
                   dist--;
                st++;
            }
            cnt+=(i-st+1);
            i++;
        }
        return cnt;
    }




class Solution {
  public:
    int countSubstr(string& s, int k) {  //this code 
        // code here
        int ans=AtMostK(s,k)-AtMostK(s,k-1);
        return ans;
        
    }
};
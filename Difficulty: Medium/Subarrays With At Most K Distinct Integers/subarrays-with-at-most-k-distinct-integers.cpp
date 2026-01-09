class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int st=0;
        int i=0;
        int n=arr.size();
        int cnt=0;
        while(i<n)
        {
            mp[arr[i]]++;
           
            while(mp.size()>k)
            {
                mp[arr[st]]--;
                if(mp[arr[st]]==0)
                 mp.erase(arr[st]);
                st++;
            }
             if(mp.size()<=k)
             cnt+=(i-st+1);
            i++;
             
        }
        return cnt;
    }
};
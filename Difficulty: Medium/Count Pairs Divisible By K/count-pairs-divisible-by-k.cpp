class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        map<int,int> mp;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            int md=arr[i]%k;
            if(md==0)
             cnt+=mp[md];
            else if(mp.find(k-md)!=mp.end())
             cnt+=mp[k-md];
            mp[md]++;
        }
        return cnt;
    }
};
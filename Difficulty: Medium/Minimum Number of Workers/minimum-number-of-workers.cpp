

struct myCmp
{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.first!=p2.first)
         return p1.first<p2.first;
        else
         return p1.second>p2.second;
    }
};
class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        vector<pair<int,int>> vc;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {  if(arr[i]==-1) continue;
            pair<int,int> p;
             p.first=max(0,i-arr[i]);
            p.second=min(n-1,i+arr[i]);
            vc.push_back(p);
        }
    sort(vc.begin(),vc.end(),myCmp());
    int cnt_min = 0;
    int currEnd = -1;
    int farthest = -1;
    int i = 0;

    while(currEnd < n - 1) {
        // try to extend coverage
        while(i < vc.size() && vc[i].first <= currEnd + 1) {
            farthest = max(farthest, vc[i].second);
            i++;
        }

        // cannot extend further → gap
        if(farthest == currEnd)
            return -1;

        cnt_min++;
        currEnd = farthest;
    }
    return cnt_min;
    
    
    }
    
};
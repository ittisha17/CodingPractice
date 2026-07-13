
struct myCmp
{
    bool operator()(int a,int b)
    {
        return a<b;
    }
};

class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,myCmp> pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        int ans=0;
        int mod=1e9+7;
        while(k-- && !pq.empty())
        {
            int elem=pq.top();
            pq.pop();
            ans=(elem+ans)%mod;
            elem--;
            if(elem!=0)
             pq.push(elem);
        }
        return ans;
    }
};
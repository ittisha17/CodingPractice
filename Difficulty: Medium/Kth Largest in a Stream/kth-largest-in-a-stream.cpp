class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int>res;
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k-1;i++)
        { res.push_back(-1);
          pq.push(arr[i]);
        }
        pq.push(arr[k-1]);
        res.push_back(pq.top());
        for(int i=k;i<n;i++)
        {
            if(arr[i]>pq.top())
             {pq.pop();
              pq.push(arr[i]);
             }
             res.push_back(pq.top());
        }
        return res;
        
        
        
    }
};
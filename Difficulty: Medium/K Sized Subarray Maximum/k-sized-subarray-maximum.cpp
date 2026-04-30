class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        deque<int> dq;
        int n=arr.size();
        int mx_id=0;
        for(int i=0;i<k;i++)
         {
             while(!dq.empty() && arr[i]>arr[dq.back()]  )
                   dq.pop_back();
             dq.push_back(i);
         }
         res.push_back(arr[dq.front()]);
     
         for(int i=k;i<n;i++)
         {
             while(!dq.empty() && dq.front()<=i-k)
              dq.pop_front();
             
               while(!dq.empty() && arr[i]>arr[dq.back()]  )
                   dq.pop_back();
    
             dq.push_back(i);
             res.push_back(arr[dq.front()]);
         }
         return res;
    }
};
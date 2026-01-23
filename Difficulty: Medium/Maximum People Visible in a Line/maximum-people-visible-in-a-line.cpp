class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int> nxt_sm;
        stack<int> prev_sm;
        vector<int> nsm(n); //no.of people smaller on right
        vector<int> psm(n); //no.of pepole smaller on left
        psm[0]=0; 
        prev_sm.push(0);
        for(int i=1;i<n;i++)
        {
            while(!prev_sm.empty() && arr[i]>arr[prev_sm.top()])
             prev_sm.pop();
            if(prev_sm.empty())
             psm[i]=i;
            else
             psm[i]=i-prev_sm.top()-1;
            prev_sm.push(i);
        }
        
        nsm[n-1]=0;
        nxt_sm.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!nxt_sm.empty() && arr[i]>arr[nxt_sm.top()])
                nxt_sm.pop();
            if(nxt_sm.empty())
             nsm[i]=n-i-1;
            else
             nsm[i]=nxt_sm.top()-i-1;
            nxt_sm.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(psm[i]+nsm[i],ans);
        }
        return ans+1;
    }
};
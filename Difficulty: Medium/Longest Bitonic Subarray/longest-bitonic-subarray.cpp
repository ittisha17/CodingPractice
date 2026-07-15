class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> lsmall(n);
        vector<int> rsmall(n);
        lsmall[0]=1;
        rsmall[n-1]=1;
        for(int i=1;i<n;i++)
        {
          if(arr[i]>=arr[i-1])
            lsmall[i]=lsmall[i-1]+1;
          else
           lsmall[i]=1;
        }
        
        for(int i=n-2;i>=0;i--)
        {
          if(arr[i]>=arr[i+1])
              rsmall[i]=rsmall[i+1]+1;
          
          else
            rsmall[i]=1;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,lsmall[i]+rsmall[i]);
        }
        return ans-1;
    }
};
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<32;i++)
        {  
            long long cnt_set=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]&(1<<i))
                 cnt_set++;
            }
            sum+=1ll*cnt_set*(n-cnt_set)*(1<<i);
        }
    
    return sum;
    }
};
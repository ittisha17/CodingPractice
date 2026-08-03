class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int> sum_left(n+1);
        sum_left[n]=0;
        sum_left[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sum_left[i]=max(arr[i],arr[i]+sum_left[i+1]);
        }
        
        int st=0;
        int i=0;
        int sum=0;
        int mx_sum=INT_MIN;
        while(i<n)
        {
            sum+=arr[i];
            if(i-st+1==k)
            {
                mx_sum=max(mx_sum,max(sum,sum+sum_left[i+1]));
                sum-=arr[st];
                st++;
            }
            i++;
        }
        return mx_sum;
        
        
    }
};
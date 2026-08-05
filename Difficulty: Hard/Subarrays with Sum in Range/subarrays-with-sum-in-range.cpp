



int lessThanEqualK(vector<int>&arr,int k)
{
    
    int n=arr.size();
    int st=0;
    int sum=0;
    int i=0;
    int cnt=0;
    while(i<n)
    {
        sum+=arr[i];
        while(sum>k)
        {
            sum-=arr[st];
            st++;
        }
        cnt+=i-st+1;
        i++;
    }
    return cnt;
    
}

int lessThanK(vector<int>&arr,int k)
{
    int n=arr.size();
    int st=0;
    int sum=0;
    int i=0;
    int cnt=0;
    while(i<n)
    {
        sum+=arr[i];
        while(sum>=k)
        {
            sum-=arr[st];
            st++;
        }
        cnt+=i-st+1;
        i++;
    }
    return cnt;
}

class Solution {
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int sublessThanlsubl=lessThanK(arr,l);
        int sublessthanEqualr=lessThanEqualK(arr,r);
        return sublessthanEqualr-sublessThanlsubl;
        
    }
};
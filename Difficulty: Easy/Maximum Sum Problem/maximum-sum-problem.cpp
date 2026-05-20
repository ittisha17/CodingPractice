class Solution {
  public:
    int Sum(int n,int &mx)
    {
        if(n==0)
         return 0;
        int part_sum=Sum(n/2,mx)+Sum(n/3,mx)+Sum(n/4,mx);
        int curr_sum=max(n,part_sum);
        mx=max(mx,curr_sum);
        return curr_sum;
    }
    int maxSum(int n) {
        // code here.
        int mx=0;
        Sum(n,mx);
        return mx;
        
        
    }
};
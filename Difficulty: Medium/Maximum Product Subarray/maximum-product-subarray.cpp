class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n=arr.size();
        int mx_pos=arr[0];
        int mx_neg=arr[0];
        
        int max_prod=mx_pos;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<0)
              swap(mx_pos,mx_neg);
            int val=arr[i];
            mx_pos=max(val,val*mx_pos);
            mx_neg=min(val,val*mx_neg);
            max_prod=max(max_prod,mx_pos);
        }
        return max_prod;
    }
};
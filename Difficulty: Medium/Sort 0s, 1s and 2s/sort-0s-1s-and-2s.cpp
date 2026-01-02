class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=-1;
        int h=n-1;
        int i=0;
        while(i<=h)
        {
            if(arr[i]==0)
             {l++;
              swap(arr[l],arr[i]);
               i++;
             }
             else if(arr[i]==2)
             {
                 swap(arr[i],arr[h]);
                 h--;
             }
             else 
              i++;
        }
    }
};
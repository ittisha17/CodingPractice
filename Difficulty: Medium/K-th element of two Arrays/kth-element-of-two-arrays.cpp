class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        int id=0;
        int arr_n;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                i++;
                id++;
                arr_n=1;
            }
            else //if(b[j]<a[i])
            {
                j++;
                id++;
                arr_n=2;
            }
            if(id==k)
            {
                if(arr_n==1)
                 return(a[i-1]);
                else
                 return(b[j-1]);
            }
        }
        while(i<n)
        {
            id++;
            i++;
            if(id==k)
             return a[i-1];
        }
        while(j<m)
        {
            id++;
            j++;
            if(id==k)
             return b[j-1];
        }
    }
};
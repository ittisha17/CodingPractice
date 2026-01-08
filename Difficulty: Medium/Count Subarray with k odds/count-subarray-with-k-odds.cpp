class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int st=0;
        int n=arr.size();
        int cnt_odd=0;
        int no_sub=0;
        int prefix_even=0;
        for(int i=0;i<n;i++)
        {   
            if(arr[i]%2==1)
             {   cnt_odd++;
                 prefix_even=0;
             }
            
            while(cnt_odd>k)
            {
                if(arr[st]%2==1) //odd no.
                 cnt_odd--;
                st++;
                prefix_even=0;
            }
            if(cnt_odd==k)
            {
                  while(st<n && arr[st]%2==0)
                   { prefix_even++;
                     st++;}
                   no_sub+=prefix_even+1;
            }
             
        }
        return no_sub;                  
    }
};  
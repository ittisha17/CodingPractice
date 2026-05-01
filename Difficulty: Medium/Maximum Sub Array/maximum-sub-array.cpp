// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        vector<int> res;
        int n=arr.size();
        int st=-1;
        int final_ln=0;
        int mx_sum=0;
        int sum=0;
        int final_start=-1;
        int i=0;
        int ln;
        while(i<n)
        {
            if(arr[i]>=0)
            { if(st==-1)
                st=i;
               sum+=arr[i];
            }
            if(arr[i]<0) //neg
            { 
              ln=i-st;
              if(sum>mx_sum)
              { mx_sum=sum;
                final_start=st;
                 final_ln=ln;
              }
              else if(sum==mx_sum)
              {  if(ln>final_ln)
                  { final_ln=ln;
                    final_start=st;
                  }
              }
              sum=0;
              
              while(i<n && arr[i]<0 )
                 i++;
               st=i;
            }
            else
             i++;
             
        }
      
        if(st!=-1) 
        {ln=n-st;
        if(sum>mx_sum)
        { mx_sum=sum;
          final_start=st;
           final_ln=ln;
        }
         else if(sum==mx_sum)
        {  if(ln>final_ln)
                  { final_ln=ln;
                    final_start=st;
                  }
        }
        }
        if(final_start==-1)
         return{-1};
        
       
        
        for(int i=final_start;i<final_start+final_ln;i++)
        {
            res.push_back(arr[i]);
        }
        return res;
        
    }
};
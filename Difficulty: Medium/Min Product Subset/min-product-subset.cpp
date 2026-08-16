class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int pos_prod=1;
        int mn_pos=11;
        int mn_neg=-11;
        int neg_prod=1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        { 
            if(arr[i]>=0)
             mn_pos=min(mn_pos,arr[i]); 
            if(arr[i]>0)
              pos_prod*=arr[i];
            if(arr[i]<0)
            {
                mn_neg=max(mn_neg,arr[i]);
                neg_prod*=arr[i];
            }
            
        }
        // cout<<"min pos-"<<mn_pos<<" pos prod-"<<pos_prod<<endl;
        // cout<<"min neg-"<<mn_neg<<" neg prod-"<<neg_prod<<endl;
        
        int ans=1;
        
        if(mn_pos==0)
         ans=0;
         
        if(neg_prod==1) //no negatives
         ans=mn_pos;
        
        if(neg_prod>=1) //if positive implies even number of negatives
         neg_prod=neg_prod/mn_neg;
        
        if(neg_prod<0 && pos_prod>0)
         ans=neg_prod*pos_prod;
         
       
       
         
        return ans ;
    }
};
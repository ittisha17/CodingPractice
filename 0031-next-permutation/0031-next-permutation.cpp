class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int piv=n-2;
        while(piv>=0)
        {
            if(nums[piv]>=nums[piv+1])
             piv--;
            else
             break;
        }
        if(piv==-1)
     {    reverse(nums.begin(),nums.end());
         return;
    }

        // the sequaece changes from index i-1
        //search in boundaries i+1 to n the lower bound of element at i-1 becomes the start and the elements remaininf in the sorted order in right?
        
        int id=0;
        for(int i=n-1;i>piv;i--)
         { if(nums[i]>nums[piv])
           {
             id=i;
             break;
           }

         }
        
        swap(nums[piv],nums[id]);
        reverse(nums.begin()+piv+1,nums.end()); 
    }
};
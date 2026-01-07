void search(int l,int h,int &mn,vector<int>&arr)
{  
    if(l<=h)
   { int mid=(l+h)/2;
    if(arr[mid]>=arr[l]) //sorted left part
    {
        mn=min(mn,arr[l]);
        search(mid+1,h,mn,arr);
    }
    else  //sorted right part
    {
        mn=min(arr[mid],mn);
        search(l,mid-1,mn,arr);
    }
   }
   return;

}


class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=INT_MAX;
        int l=0;
        int h=nums.size()-1;
        search(l,h,mn,nums);
        return mn;
    }
};
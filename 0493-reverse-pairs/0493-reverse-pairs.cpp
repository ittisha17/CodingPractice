
void mergeCnt(int l,int mid,int h,vector<int>&arr,int&cnt)
{
    vector<int>temp;
    int i=l;
    int j=mid+1;

    int idx=l;
    int j1=mid+1;
    while(j1<=h)
    {
        while(idx<=mid && arr[idx]<=(1ll*2*arr[j1]))
         idx++;
        cnt+=mid-idx+1;
        j1++;
    }
    while(i<=mid && j<=h)
        {
            if(arr[i]<arr[j])
             {temp.push_back(arr[i]);
             i++;}
            else //arr[i]>arr[j]
             {  
                // if(arr[i]>(2*arr[j])) 
                //    cnt+=mid-i+1;
                temp.push_back(arr[j]);
                j++;
             }
        }
        while(i<=mid)
         {
             temp.push_back(arr[i]);
             i++;
         }
        while(j<=h)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i=0;i<temp.size();i++)
        {
            arr[l+i]=temp[i];
        }
}



void cnt_inv(int l,int h,vector<int>&arr,int&cnt)
{   
    if(l==h) return;
    int mid=l+(h-l)/2;
    cnt_inv(l,mid,arr,cnt);
    cnt_inv(mid+1,h,arr,cnt);
    mergeCnt(l,mid,h,arr,cnt);
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
         int cnt=0;
        int l=0;
        int h=nums.size()-1;
        cnt_inv(l,h,nums,cnt);
        return cnt;
        
    }
};
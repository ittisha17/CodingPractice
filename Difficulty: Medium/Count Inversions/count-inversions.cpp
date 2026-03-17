




void mergeCnt(int l,int mid,int h,vector<int>&arr,int&cnt)
{
    vector<int>temp;
    int i=l;
    int j=mid+1;

        while(i<=mid && j<=h)
        {
            if(arr[i]<=arr[j])
             {temp.push_back(arr[i]);
             i++;}
            else //arr[i]>arr[j]
             {
                 cnt+=mid-i+1;
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
    int inversionCount(vector<int> &arr) {
        // Code Here
        int cnt=0;
        int l=0;
        int h=arr.size()-1;
        cnt_inv(l,h,arr,cnt);
        return cnt;
        
    }
};
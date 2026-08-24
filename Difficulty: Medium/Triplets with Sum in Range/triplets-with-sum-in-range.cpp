



int countgreaterthanR(vector<int>&arr,int r)
{
    int n=arr.size();
    int i=0;
    int cnt=0;
    while(i<n-2)
    {
        int k=i+1;
        int j=n-1;
        while(k<j)
        {  
            long long sum=arr[i]+arr[k]+arr[j];
            if(sum>r)
            {
               cnt+=j-k; 
               j--;
            }
            else
             k++;
        }
      i++;
    }
    return cnt;
}

int countlessthanL(vector<int>&arr,int l)
{   
    int n=arr.size();
    int i=0;
      int j=n-1;
    int cnt=0;
    while(i<n-2)
    {
        int k=i+1;
        j=n-1;
        while(k<j)
       { long long  sum=arr[i]+arr[k]+arr[j];
         if(sum<l)
          {
            cnt+=j-k;
            k++;
          }
        else
          j--;
       }
       i++;
    }
    return cnt;
}

class Solution {
  public:
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int lessLcnt=countlessthanL(arr,l);
        int greaterRcnt=countgreaterthanR(arr,r);
        long long total_triplets=(n*(n-1)*(n-2))/6;
        long long res=total_triplets-lessLcnt-greaterRcnt;
        return (int)res;
    }
    
};
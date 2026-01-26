bool isFeas(long long k,int hrs,vector<int>&piles)
{  long long hrs_took=0;
    for(int i=0;i<piles.size();i++)
    {   
        if(piles[i]==0) continue;
        if(piles[i]<k)
         hrs_took++;
        else
        {   
            if(piles[i]%k==0)
             hrs_took+=(long long)piles[i]/k;
            else
             hrs_took+=(long long)piles[i]/k+1;
        }
       
     }
       return hrs_took<=hrs;
}

long long Bsearch(long long l,long long h,vector<int>&piles,int hrs)
{  long long k;
    while(l<=h)
   { long long mid=(l+h)/2;
     if(isFeas(mid,hrs,piles))
     {
        k=mid;
        h=mid-1;
     }
     else
      l=mid+1;
   }
   return k;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int mx_val=piles[0];
        long long total_bn=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            total_bn+=piles[i];
            mx_val=max(mx_val,piles[i]);
        }
        long long l=max(1LL,total_bn/hrs); //min number of bananas it should eat every hour
        long long h=mx_val; //max value of banas it can eat at any hour is the pile with max banas
        //int k;
        return (int)Bsearch(l,h,piles,hrs);
        


    }
};
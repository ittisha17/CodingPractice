
bool isPoss(int days,vector<int>&vec,int m,int k,int n)
{
    int i=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {   if(vec[i]<=days)
        {cnt++;
          if(cnt==k)
          {
             m--;
             cnt=0;
          }
        }
        else
         cnt=0;
        
    }
    return m<=0;
}


class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=INT_MAX;
        int h=INT_MIN;
        int n=bloomDay.size();
        for(int i=0;i<n;i++)
        {
            l=min(bloomDay[i],l);
            h=max(bloomDay[i],h);
        }

        //if(m*k > n)return -1;
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPoss(mid,bloomDay,m,k,n))
            {
                ans=mid;
                h=mid-1;
            }
            else
             l=mid+1;
        }
        return ans;
    }
};
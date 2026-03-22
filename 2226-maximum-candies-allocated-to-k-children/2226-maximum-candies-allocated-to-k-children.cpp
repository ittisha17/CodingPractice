
bool isPoss(int num,vector<int>&candies,long long k)
{
    long long  cnt=0;
    for(int i=0;i<candies.size();i++)
    {
        cnt+=candies[i]/num;
    }
    return cnt>=k ;
}

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1;
        int n=candies.size();
        sort(candies.begin(),candies.end());
        int h=candies[n-1];
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPoss(mid,candies,k))
            {
               ans=mid;
               l=mid+1;
            }
            else
             h=mid-1;
        }
        return ans;

    }
};
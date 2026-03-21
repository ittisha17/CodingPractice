class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mx=0;
        int n=cardPoints.size();
        vector<int> pre_sum(n);
        vector<int> post_sum(n);
        pre_sum[0]=cardPoints[0];
        post_sum[n-1]=cardPoints[n-1];
        for(int i=1;i<n;i++)
        {
            pre_sum[i]=cardPoints[i]+pre_sum[i-1];
            post_sum[n-i-1]=cardPoints[n-i-1]+post_sum[n-i];
        }

        for(int i=0;i<=k;i++)
        {  int sum=0;
           if(i==0)
            sum=post_sum[n-k];
           else if(i==k)
            sum=pre_sum[k-1];
           else
            sum=pre_sum[i-1]+post_sum[n-k+i];
          mx=max(mx,sum);
        }
        return mx;
    }
};
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<int>curr(target+1);
        vector<int> prev(target+1,0);
        prev[0]=1;
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<=target;j++)
            {   
                curr[j]=prev[j];  //not included
                if(j>=arr[i])
                 curr[j]+=prev[j-arr[i]]; //included
            }
            prev=curr;
        }
        return curr[target];
      
    }
};
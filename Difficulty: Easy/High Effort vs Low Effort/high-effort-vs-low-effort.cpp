class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        vector<vector<int>> vec(n,vector<int>(3));
        vec[0][0]=0;
        vec[0][1]=l[0];
        vec[0][2]=h[0];
        
        for(int i=1;i<n;i++)
        {
            vec[i][0]=max(vec[i-1][1],vec[i-1][2]);
            vec[i][1]=l[i]+max(vec[i-1][2],vec[i-1][1]);
            vec[i][2]=h[i]+vec[i-1][0];
        }
        int ans=max(vec[n-1][0],max(vec[n-1][1],vec[n-1][2]));
        return ans;
    }
};
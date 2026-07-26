class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
    int n=arr.size();
    vector<vector<int>>res;
    queue<int>q;
    q.push(0); //store indexes
    while(!q.empty())
    {
        int sz=q.size();
        vector<int>temp;
        for(int i=0;i<sz;i++)
        {
            int idx=q.front();
            temp.push_back(arr[idx]);
            q.pop();
            if(2*idx+1<n)   //lchild
             q.push(2*idx+1);
            if(2*idx+2<n)    //rchild
             q.push(2*idx+2);
            
        }
        sort(temp.begin(),temp.end());
        res.push_back(temp);
    }
    return res;
    }
};

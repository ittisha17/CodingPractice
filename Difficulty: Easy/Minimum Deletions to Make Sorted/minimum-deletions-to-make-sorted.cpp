class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
       int n = arr.size();

        vector<int> tails;

        for (int x : arr) {
            auto it = lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end())
                tails.push_back(x);
            else
                *it = x;
        }

        return n - tails.size();
        
        
    }
};
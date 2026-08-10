class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(n));

        // First row
        for(int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        // Remaining rows
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {

                int best = 0;

                // Previous row, but different column
                for(int k = 0; k < n; k++) {
                    if(k != j) {
                        best = max(best, dp[i-1][k]);
                    }
                }

                dp[i][j] = mat[i][j] + best;
            }
        }

        // Maximum value in last row
        int ans = 0;

        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[n-1][j]);
        }

        return ans;
    }
};
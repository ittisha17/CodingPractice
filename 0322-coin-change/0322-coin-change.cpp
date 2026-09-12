
const int mx=1e4;



    const long long INF = 1e9;

    long long coins_req(
        int id,
        int amount,
        vector<int>& coins,
        vector<vector<long long>>& dp
    ) {

        if (amount == 0)
            return 0;

        if (id >= coins.size())
            return INF;

        if (coins[id] > amount)
            return INF;

        if (dp[id][amount] != -1)
            return dp[id][amount];

        long long take =
            coins_req(id, amount - coins[id], coins, dp);

        if (take != INF)
            take++;

        long long notTake =
            coins_req(id + 1, amount, coins, dp);

        return dp[id][amount] = min(take, notTake);
    }


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<long long>> dp(n,vector<long long>(mx+1,-1));
        int idx=0;
        long long ans=coins_req(idx,amount,coins,dp);
        return (ans==INF?-1:(int)ans);

    }
};
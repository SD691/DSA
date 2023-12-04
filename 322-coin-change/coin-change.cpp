class Solution {
public:

    int minElement(vector<int> &coins, int ind, int target, vector<vector<int>> &dp){
        if(ind == 0){
            if(target%coins[0] == 0) return target/coins[0];
            else return 1e9;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notTaken = 0+minElement(coins,ind-1,target,dp);
        int taken = 1e9;
        if(coins[ind]<=target){
            taken = 1+minElement(coins,ind,target-coins[ind],dp);
        }
        return dp[ind][target] = min(notTaken,taken);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = minElement(coins,n-1,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};
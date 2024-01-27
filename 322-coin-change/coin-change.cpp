class Solution {
public:
    int helper(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp){
        
        if(ind==coins.size()) return 1e9;
        if(amount==0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTaken = helper(ind+1,coins,amount,dp);
        int taken = 1e9;
        if(amount-coins[ind]>=0){
            amount= amount-coins[ind];
            taken = 1+helper(ind,coins,amount,dp);
            amount = amount+coins[ind];
        }
        return dp[ind][amount] = min(taken,notTaken);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int val = helper(0,coins,amount,dp);
        if(val==1e9) return -1;
        return val;
    }
};
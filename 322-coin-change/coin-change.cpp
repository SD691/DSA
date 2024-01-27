class Solution {
public:
    int helper(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp){
        
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(amount==0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTaken = helper(ind-1,coins,amount,dp);
        int taken = 1e9;
        if(coins[ind]<=amount){
            amount= amount-coins[ind];
            taken = 1+helper(ind,coins,amount,dp);
            amount = amount+coins[ind];
        }
        return dp[ind][amount] = min(taken,notTaken);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int val = helper(n-1,coins,amount,dp);
        if(val==1e9) return -1;
        return val;
    }
};
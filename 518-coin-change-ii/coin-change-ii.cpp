class Solution {
public:

    int solve(int ind, int val, int amount, vector<int> &coins, vector<vector<int>> &dp ){
        if(amount==0){
            return 1;
        }if(ind==coins.size()){
            return 0;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTaken  = solve(ind+1,val,amount,coins,dp);
        int taken = 0;
        if(coins[ind]<=amount){
            taken = solve(ind,val,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount] = taken+notTaken;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(0,0,amount,coins,dp);
    }
};
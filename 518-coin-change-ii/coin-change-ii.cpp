class Solution {
public:
    int solve(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp, int amount ){
        if(ind==coins.size()){
            return 0;
        }
        if(sum==amount){
            return 1;
        }

        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notTaken = solve(ind+1,sum,coins,dp,amount);
        int taken = 0;
        if(sum+coins[ind]<=amount){
            taken = solve(ind,sum+coins[ind],coins,dp,amount);
        }

        return dp[ind][sum] = taken+notTaken;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(0,0,coins,dp,amount);
    }
};
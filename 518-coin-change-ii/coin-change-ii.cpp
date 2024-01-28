class Solution {
public:
    int helper(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp, int &sum){
        if(sum==amount){
            return 1;
        }
        if(ind<0) return 0;

        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notTaken = helper(ind-1,coins,amount,dp,sum);
        int taken = 0;
        if(sum+coins[ind]<=amount){
            sum = sum+coins[ind];
            taken = helper(ind,coins,amount,dp,sum);
            sum = sum-coins[ind];
        }
        return dp[ind][sum] = taken+notTaken;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int sum = 0;
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,coins,amount,dp,sum);
    }
};
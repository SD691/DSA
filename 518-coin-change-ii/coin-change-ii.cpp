class Solution {
public:
    int solve(int ind, int amt, int amount, vector<int> &coins, vector<vector<int>> &dp, int n){
        if(ind==n){
            return 0;
        }
        if(amt==amount){
            return 1;
        }

        if(dp[ind][amt]!=-1) return dp[ind][amt];

        int notTaken =solve(ind+1,amt,amount, coins,dp,n);
        int taken = 0;
        if(amt+coins[ind]<=amount){
            amt += coins[ind];
            taken = solve(ind,amt,amount,coins,dp,n);
            amt -= coins[ind]; 
        }

        return dp[ind][amt] = taken+notTaken;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount,-1));
        return solve(0,0,amount,coins,dp,n);
    }
};
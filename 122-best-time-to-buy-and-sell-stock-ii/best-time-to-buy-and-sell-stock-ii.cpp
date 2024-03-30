class Solution {
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp, int n){
        if(ind==n){
            return 0;
        }

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==0){
            dp[ind][buy] = max(-prices[ind]+solve(ind+1,1,prices,dp,n), solve(ind+1,0,prices,dp,n));
        }
        if(buy==1){
            dp[ind][buy] = max(prices[ind]+solve(ind+1,0,prices,dp,n),solve(ind+1,1,prices,dp,n));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp,n);
    }
};
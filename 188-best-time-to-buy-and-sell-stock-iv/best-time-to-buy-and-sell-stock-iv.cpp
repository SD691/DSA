class Solution {
public:

    int getAns(vector<int> &prices, int n, int ind, int buy, int k, vector<vector<vector<int>>> &dp){
        if(ind==n || k==0) return 0;
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];

        int profit;
        if(buy == 0){
            profit = max(0 + getAns(prices,n,ind+1,0,k,dp), -prices[ind] + getAns(prices,n,ind+1,1,k,dp));
        }
        if(buy == 1){
            profit = max(0 + getAns(prices,n,ind+1,1,k,dp), prices[ind] + getAns(prices,n,ind+1,0,k-1,dp));
        }
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return getAns(prices,n,0,0,k,dp);
    }
};
class Solution {
public:
    int find(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size()){
            return 0;
        }

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==0){
            dp[ind][buy] = max(-prices[ind] + find(ind+1,1,prices,dp), 0+find(ind+1,0,prices,dp));
        }
        else{
            dp[ind][buy] = max(prices[ind] + find(ind+1,0,prices,dp), 0+find(ind+1,1,prices,dp));
        }

        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(0,0,prices,dp);
    }
};
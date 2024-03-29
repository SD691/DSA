class Solution {
public:
    int find(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==prices.size() || cap==3) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        if(buy==0){
            dp[ind][buy][cap] = max(-prices[ind]+find(ind+1,1,cap+1,prices,dp), 0+find(ind+1,0,cap,prices,dp));
        }
        else{
            dp[ind][buy][cap] = max(prices[ind]+find(ind+1,0,cap,prices,dp), 0+find(ind+1,1,cap,prices,dp));
        }
        return dp[ind][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return find(0,0,0,prices,dp);
    }
};
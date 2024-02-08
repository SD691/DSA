class Solution {
public:
    int helper(int ind, int sum, int n, vector<vector<int>> &dp){
        if(sum==0){
            return 0;
        }
        if(ind==0){
            return INT_MAX;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        int notTaken = 0+helper(ind-1,sum,n,dp);
        int taken= 1e9;
        if (ind * ind <= sum) {
            taken = 1 + helper(ind, sum - ind * ind, n, dp);
        }
        return dp[ind][sum] = min(taken,notTaken);
    }
    int numSquares(int n) {
        int sum = 0;
        int ind= sqrt(n);
        vector<vector<int>> dp(ind+1,vector<int>(n+1,-1));

        for(int i=0; i<=ind; i++){
            dp[i][0]= 0;
        }

        for(int i=0; i<=n; i++){
            dp[0][i] = INT_MAX;
        }

        for(int i=1; i<=ind; i++){
            for(int j=1; j<=n; j++){
                int notTaken = 0+dp[i-1][j];
                int taken= 1e9;
                if (i * i <= j) {
                    taken = 1 + dp[i][j-i*i];
                }
                dp[i][j] = min(taken,notTaken);
            }
        }
        return dp[ind][n];
    }
};
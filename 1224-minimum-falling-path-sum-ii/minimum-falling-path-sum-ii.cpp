class Solution {
public:

    int solve(int row, int col, vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(row==grid.size()-1){
            return grid[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int n = grid.size();
        int val = 1e9;
        if(col-1>-1){
            for(int i=col-1; i>-1; i--){
                if(dp[row][col]!=-1){
                    dp[row][col] = min(dp[row][col],grid[row][col] + solve(row+1,i,grid,dp));
                }
                else{
                    dp[row][col] = min(val,grid[row][col] + solve(row+1,i,grid,dp));
                }
                
            }
        }
        if(col+1<n){
            for(int i=col+1; i<n; i++){
                if(dp[row][col]!=-1){
                    dp[row][col] = min(dp[row][col],grid[row][col]+solve(row+1,i,grid,dp));
                }
                else{
                    dp[row][col] = min(val,grid[row][col] + solve(row+1,i,grid,dp));
                }
                
            }
        }
        
        
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans,solve(0,i,grid,dp));
        }
        return ans;
    }
};
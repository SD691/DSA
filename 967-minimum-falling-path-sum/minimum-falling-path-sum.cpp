class Solution {
public:
    int helper(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (col < 0 || col > matrix[0].size() - 1) {
            return 1e9;
        }
        if (row == 0) {
            return matrix[row][col];
        }

        if (dp[row][col] != -1) return dp[row][col];

        int left = matrix[row][col] + helper(row - 1, col - 1, matrix, dp);
        int up = matrix[row][col] + helper(row - 1, col, matrix, dp);
        int right = matrix[row][col] + helper(row - 1, col + 1, matrix, dp);

        return dp[row][col] = min(left, min(up, right));
    }

    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<m; i++){
            dp[0][i] = matrix[0][i];
        }
        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int up = matrix[i][j]+dp[i-1][j];
                int left = INT_MAX;
                if(j-1>-1){
                    left = matrix[i][j] + dp[i-1][j-1];
                }
                int right = INT_MAX;
                if(j+1<m){
                    right = matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j] = min(up,min(left,right));
            }
        }
        for(int i=0; i<m; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};

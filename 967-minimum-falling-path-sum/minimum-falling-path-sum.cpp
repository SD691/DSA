class Solution {
public:

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

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0; i<n; i++){
            if(matrix[i][0]==1){
                dp[i][0] = matrix[i][0];
                ans++;
            }
        }
        for(int i=1; i<m; i++){
            if(matrix[0][i]==1){
                dp[0][i] = matrix[0][i];
                ans++;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]!=0){
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                   ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};
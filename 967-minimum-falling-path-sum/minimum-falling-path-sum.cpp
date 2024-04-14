class Solution {
public:
    int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(row==matrix.size()-1){
            return matrix[row][col];
        }

        if(dp[row][col]!=-1) return dp[row][col];
        int n= matrix.size();
        int left = 1e9;
        int right = 1e9;
        int down = 1e9;
        if(row+1<n && col-1>-1){
            left = matrix[row][col]+solve(row+1,col-1,matrix,dp);
        }
        if(row+1<n && col+1<n){
            right = matrix[row][col]+solve(row+1,col+1,matrix,dp);
        }
        if(row+1<n){
            down = matrix[row][col]+solve(row+1,col,matrix,dp);
        }

        return dp[row][col] = min(left,min(right,down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = 1e9;

        for(int i=0; i<n; i++){
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1; i<n;i++){
            for(int j=0; j<n; j++){
                int left = 1e9;
                int right = 1e9;
                int down = 1e9;
                if(j<n-1){
                    left = matrix[i][j]+dp[i-1][j+1];
                }               
                if(j>0){
                    right = matrix[i][j] +dp[i-1][j-1];
                }
                down= matrix[i][j]+dp[i-1][j];

                dp[i][j] = min(left,min(right,down));
            }
        }

        for(int i=0; i<n; i++){
            ans = min(dp[n-1][i],ans);
        }
        return ans;
    }
};
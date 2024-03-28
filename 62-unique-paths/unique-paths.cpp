class Solution {
public:
    int find(int row, int col, vector<vector<int>> &dp,int n, int m){
        if(row==n-1 && col==m-1){
            return 1;
        }
        if(dp[row][col]!=-1) return dp[row][col];

        int right= 0;
        int down =0;

        if(row+1<n){
            down = find(row+1,col,dp,n,m);
        }
        if(col+1<m){
            right = find(row,col+1,dp,n,m); 
        }

        return dp[row][col] = down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return find(0,0,dp,n,m);
    }
};
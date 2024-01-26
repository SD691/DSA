class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, memo);
    }

    int dfs(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>>& memo) {
      
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        } 
        if (maxMove == 0) {
            return 0;
        }
        if (memo[row][col][maxMove] != -1) {
            return memo[row][col][maxMove];
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int result = 0;
            for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            result = (result + dfs(m, n, maxMove - 1, nrow, ncol, memo)) % MOD;
        }
        memo[row][col][maxMove] = result;
        return result;
    }

};

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, memo);
    }

    int dfs(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>>& memo) {
        // Check if out of bounds
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }

        // Check if out of moves
        if (maxMove == 0) {
            return 0;
        }

        // Check if result for this state is already memoized
        if (memo[row][col][maxMove] != -1) {
            return memo[row][col][maxMove];
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int result = 0;

        // Explore in all four directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            // Calculate the number of paths recursively
            result = (result + dfs(m, n, maxMove - 1, nrow, ncol, memo)) % MOD;
        }

        // Memoize the result
        memo[row][col][maxMove] = result;
        return result;
    }

private:
    const int MOD = 1e9 + 7;
};

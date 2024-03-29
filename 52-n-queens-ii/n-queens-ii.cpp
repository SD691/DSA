class Solution {
public:
bool isSafe(int row, int col, vector<string> &board, int n){

        int nrow = row;
        int ncol = col;

        while(row>-1 && col>-1){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row = nrow;
        col = ncol;
        while(col>-1){
            if(board[row][col]=='Q') return false;
            col--;
        }

        col = ncol;

        while(col>-1 && row<n){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        solve(0,board,ans,n);
        return ans.size();
    }
};
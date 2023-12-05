class Solution {
public:

    bool helper(int row, int col, vector<vector<char>>& board, string word, int ind, bool val ){
        if(ind==word.size()){
          
            return true;
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            char original;
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && board[nrow][ncol]==word[ind]){
                original = board[nrow][ncol];
                board[nrow][ncol]='#';
                if(helper(nrow,ncol,board,word,ind+1,val)){
                    return true;
                }
                board[nrow][ncol] = original;
            } 
            
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool val;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                char original2;
                if(board[i][j] == word[0]){
                    original2 = board[i][j];
                    board[i][j] = '#';
                    if(helper(i,j,board,word,1,val)==true){
                        return true;
                    }
                    board[i][j] = original2;
                }
            }
        }

        
        return false;
    }
};
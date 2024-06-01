class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(( i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                    dp[i][j] = 1;
                }
                
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();


            int row = it.first;
            int col = it.second;

            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>-1 && nrow<n && ncol>-1 && ncol<m && dp[nrow][ncol]==-1 && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    dp[nrow][ncol] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]==1){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
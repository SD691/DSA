class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>& grid,vector<vector<int>> &vis ){
        queue<pair<int,int>> q;
        q.push({i,j});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>-1 && nrow<grid.size() && ncol>-1&& ncol<grid[0].size() && vis[nrow][ncol]==-1 && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){
                    count++;
                    vis[i][j]=1;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};
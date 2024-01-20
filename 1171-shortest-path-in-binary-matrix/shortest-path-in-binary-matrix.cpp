class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0) return -1;
        if(grid[n-1][n-1]!=0) return -1;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,-1));
        q.push({{0,0},1});
        int sum = INT_MAX;

        while(!q.empty()){
            //auto it: q.front();
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            q.pop();
            if(vis[row][col]==1) continue;
            if(row==n-1 && col==n-1){
                sum = min(sum,level);
            }
            vis[row][col] = 1;
            int drow[] = {-1,-1,-1,0,1,1,1,0};
            int dcol[] = {-1,0,1,1,1,0,-1,-1};

            for(int i=0; i<8; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>-1 && nrow<n && ncol>-1 && ncol<n && grid[nrow][ncol]==0 && vis[nrow][ncol]==-1){
                    q.push({{nrow,ncol},level+1});
                }
            } 
        }
        if(sum==INT_MAX){
            return -1;
        }
        return sum;

    }
};
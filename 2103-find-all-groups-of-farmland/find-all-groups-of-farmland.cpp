class Solution {
public:
    pair<int,int> bfs(vector<vector<int>>& land, vector<vector<int>>& vis, int row, int col){
        queue<pair<int,int>> q;
        q.push({row,col});
       
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        pair<int,int> p;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(((col+1<land[0].size() && land[row][col+1]==0) || col+1==land[0].size()) && 
            ((row+1<land.size() && land[row+1][col]==0) || row+1==land.size())){
                p.first = row;
                p.second = col;
                break; 
            }
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<land.size() && ncol>=0 && ncol<land[0].size() && 
                land[nrow][ncol]==1 && vis[nrow][ncol]==-1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return p;

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j]==1 && vis[i][j]==-1){
                    vis[i][j]=1;
                    pair<int,int> pm = bfs(land,vis,i,j);
                    ans.push_back({i, j, pm.first, pm.second});
                }   
            }
        }
        return ans;
    }
};
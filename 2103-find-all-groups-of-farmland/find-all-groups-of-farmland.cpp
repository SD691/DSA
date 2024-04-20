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

            int row1,row2,col1,col2;
             row1 = row;
             col1 = col+1;
             row2 = row+1;
             col2 = col;

            bool val = false;
            if(((col1<land[0].size() && land[row1][col1]==0) || col1==land[0].size()) && 
            ((row2<land.size() && land[row2][col2]==0) || row2==land.size())){
                val = true;
            }
            if(val==true){
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
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vis[i][j]=1;
                    pair<int,int> pm = bfs(land,vis,i,j);
                    temp.push_back(pm.first);
                    temp.push_back(pm.second);
                    ans.push_back(temp);
                }
                
            }
        }
        return ans;
    }
};
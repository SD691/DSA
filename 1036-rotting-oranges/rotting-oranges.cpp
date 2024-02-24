class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }

        int ans = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
            ans = max(ans,cost);
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>-1 && nrow<grid.size() && ncol>-1 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({cost+1,{nrow,ncol}});
                }
            }
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
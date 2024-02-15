class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]!=0 || grid[0][0]!=0) return -1;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({1,{0,0}});

        int drow[] = {-1,-1,-1,0,1,1,1,0};
        int dcol[] = {-1,0,1,1,1,0,-1,-1};
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int level = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row==n-1 && col==m-1){
                return level;
            }
            for(int i=0; i<8; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>-1 && nrow<n && ncol>-1 && ncol<m && grid[nrow][ncol]==0) {
                    pq.push({level+1,{nrow,ncol}});
                    grid[nrow][ncol] = 1;
                }

            }
        }
        return -1;
    }
};
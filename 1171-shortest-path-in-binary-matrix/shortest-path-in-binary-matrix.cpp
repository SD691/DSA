class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==0){
            q.push({0,{0,0}});
        }
        else{
            return -1;
        }

        

        int n = grid.size();
        int m = grid[0].size();

        if(n-1==0 && m-1==0) return 1;

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;

        int drow[] = {-1,-1,-1,0,1,1,1,0};
        int dcol[] = {-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            for(int i=0; i<8; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol] = dis+1;

                    if(nrow == n-1 && ncol ==m-1){
                        return dis+2;
                    }
                    q.push({dis+1,{nrow,ncol}});
                }
            }


        }
        return -1;
    }
};
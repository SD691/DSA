class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,  greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dp(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dp[0][0] = 0;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int diff = node.first;
            int row = node.second.first;
            int col = node.second.second;

            if(row==n-1 && col==m-1) return diff;
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                    int absdiff = max(abs(heights[row][col]-heights[nrow][ncol]), diff);

                    if(dp[nrow][ncol]>absdiff){
                        dp[nrow][ncol] = absdiff;
                        pq.push({absdiff,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
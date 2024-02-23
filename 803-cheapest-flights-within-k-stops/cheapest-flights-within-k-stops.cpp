class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0; i<flights.size(); i++){
            int edg = flights[i][0];
            int adjE = flights[i][1];
            int wt = flights[i][2];
            adj[edg].push_back({adjE,wt});
        }

        queue<pair<int,pair<int,int>>> q;

        q.push({src,{0,0}});
        vector<int> dis(n,1e9);
        dis[src] = 0;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int edg = it.first;
            int wt = it.second.first;
            int level = it.second.second;

            if(level==k+1){
                continue;
            }

            for(auto it: adj[edg]){
                int node = it.first;
                int dist = it.second;
                if(dis[node]>wt+dist){
                    dis[node] = wt+dist;
                    q.push({node,{dis[node],level+1}});
                }
            }
        }
        if(dis[dst]==1e9){
            return -1;
        }
        return dis[dst];
    }
};
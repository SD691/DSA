class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        vector<int> dis(n,1e9); 

        while(!pq.empty()){
            auto node = pq.front();
            pq.pop();
            int price = node.first;
            int adjNode = node.second.first;
            int level = node.second.second;


            for(auto it: adj[adjNode]){
                int adjn = it.first;
                int cost= it.second;
                if(dis[adjn]>cost+price && level<=k){
                    dis[adjn] = cost+price;
                    pq.push({price+cost,{adjn,level+1}});
                }
            }
             
        }
        if(dis[dst]!=1e9){
            return dis[dst];
        }
        return -1;
    }
};
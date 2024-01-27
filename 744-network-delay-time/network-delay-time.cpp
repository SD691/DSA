class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        vector<int> dis(n+1,1e9);
        dis[k] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int time = it.second;
            for(auto itr: adj[node]){

                int adjNode = itr.first;
                int adjTime = itr.second;

                if(dis[adjNode]> time+adjTime ){
                    dis[adjNode] = time+adjTime;
                    q.push({adjNode,time+adjTime});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dis[i]==1e9){
                return -1;
            }
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>> > adj(n);
        
        for (auto it : roads) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<bool> visited(n, false);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            
            if (visited[node]) {
                continue;
            }
            visited[node] = true;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long edW = it.second;

                if (dist[node] + edW < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edW;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dist[node] + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
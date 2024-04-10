class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> color(n, 'o'); // 'o' for uncolored, 'a' and 'b' for two colors
        vector<int> vis(n, 0); // 0 for unvisited, 1 for visited
        queue<pair<int, char>> q;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                q.push({i, 'a'});
                vis[i] = 1;

                while (!q.empty()) {
                    int node = q.front().first;
                    char col = q.front().second;
                    q.pop();

                    if (color[node] == 'o') {
                        color[node] = col;
                    }

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == col) {
                            return false; // Not bipartite
                        } else if (!vis[neighbor]) {
                            q.push({neighbor, (col == 'a' ? 'b' : 'a')});
                            vis[neighbor] = 1;
                        }
                    }
                }
            }
        }
        
        return true; // Bipartite
    }
};
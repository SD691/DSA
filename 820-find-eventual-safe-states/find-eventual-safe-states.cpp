class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        vector<int> indegree(V,0);

        for(int i=0; i<V; i++){
            for(int neighbour: graph[i]){
                adj[neighbour].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(int neighbour: adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

            sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;

    }
};
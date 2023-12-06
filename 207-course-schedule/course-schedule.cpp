class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses; // Number of courses
        vector<int> adj[V];
        vector<int> ind(V, 0); 
        

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                ind[it]--;
                if (ind[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (topo.size() == numCourses) {
            return true;
        }
        return false;
            
        
    }
};
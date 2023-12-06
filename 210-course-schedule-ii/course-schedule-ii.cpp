class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;

        vector<int> adj[numCourses];
        int ind[V];
        for(int i=0;i<V;i++){
            ind[i] = 0;
        }

    
            for(auto it: prerequisites){
                adj[it[1]].push_back(it[0]);
                
            }
    

        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }

        if(topo.size()==V){
            return topo;
        }
        return {};
    }
};
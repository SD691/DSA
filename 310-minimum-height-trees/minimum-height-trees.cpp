class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; 
        vector<int> adj[n];
        vector<int> ind(n,0);
        vector<int> ans;

        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
            ind[a]++;
            ind[b]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(ind[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int n = q.size();
            ans.clear();
            for(int i=0; i<n; i++){
                int node= q.front();
                q.pop();
                ans.push_back(node);
                
                for(auto it: adj[node]){
                    ind[it]--;
                    if(ind[it]==1){
                        q.push(it);
                    }
                }

            }
        }
        return ans;
    }
};
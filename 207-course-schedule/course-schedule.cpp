class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> ind(numCourses,0);

        for(int i=0; i<prerequisites.size(); i++){
            int a =prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            ind[a]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(ind[i]==0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }

        if(topo.size()==numCourses) return true;
        return false;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];

        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n+1,0);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(vis[i]==0){
                ans++;
                vis[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it: adj[node]){
                        if(vis[it]==0){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
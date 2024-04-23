class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int> adj[n];

        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
            
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++){

            priority_queue<int> pq;
            int val = vals[i];
            

            for(auto it: adj[i]){
                pq.push(vals[it]);
            }

            int opt = k;
            
            while(opt>0 && !pq.empty()){
                if(pq.top()>-1){
                    val += pq.top();
                }
                
                pq.pop();
                opt--;
            }
            ans = max(val,ans);
            
        }
        return  ans;
    }
};
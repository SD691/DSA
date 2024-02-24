class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        for (auto it : meetings) {

            // dekho undirected graph bna rha thik
            // lekin ek minute...(carry minati \U0001f602)
            // kyu abhi bhai
            // arey meeting hai n
            // chahe x y se kre ya y x se baat to same hi hai
            // arey tum apni GF/BF se baat kro ya phir vo tumse
            // baat to ho rhi hai n
            // flow bidirectional huaa n...Bas (\U0001f937‍♂️)
            // dekho bhai bhatkna nhi hai..abhi approach samjho..
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        vector<int> vis(n,0);
        
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int time = it.first;
            int know = it.second;


            if(vis[know]!=0){
                continue;
            }
            vis[know] = 1;
            for(auto it: adj[know]){
                if(vis[it.first]==0 && it.second>=time){
                    pq.push({it.second,it.first});
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(vis[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
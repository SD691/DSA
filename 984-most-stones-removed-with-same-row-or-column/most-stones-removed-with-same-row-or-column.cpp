class DisjointSet{
    public:
    vector<int> size,parent,rank;
    
    DisjointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for(auto it: stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> mp;
        for(auto it: stones){
            int row = it[0];
            int col = it[1]+maxrow+1;
            ds.unionBySize(row,col);
            mp[row] = 1;
            mp[col] = 1;
        }

        int cnt = 0;
        for(auto it: mp){
            if(ds.parent[it.first] == it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};
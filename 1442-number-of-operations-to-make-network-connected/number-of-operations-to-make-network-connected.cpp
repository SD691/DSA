class DisjointSet{
    public:
    vector<int> size,parent;
    
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        DisjointSet ds(n);

        int count = 0;
        int extra = 0;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionBySize(u,v);
            }
            else{
                extra++;
            }
        }

        int cntC = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i) cntC++;
        }
        int ans = cntC-1;
        if(extra>=ans) return ans;
        return -1;

    }
};
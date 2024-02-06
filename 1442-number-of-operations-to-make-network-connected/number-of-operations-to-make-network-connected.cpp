class DisjointSet{
    public:
    vector<int> size,parent;
    
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        //here i can initialise the parent outside the class and have no error, but when it comes to older versions of the class that is not possible, i have to use constructor t initialise the classs
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
        DisjointSet ds(n);

        int extra = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionBySize(u,v);
            }
            else{
                extra++;
            }
        }

        int connect = 0;
        for(int i=0; i<ds.parent.size(); i++){
            if(ds.parent[i]==i){
                connect++;
            }
        }
        connect -= 1;
        if(connect<=extra){
            return connect;
        }
        return -1;

    }
};
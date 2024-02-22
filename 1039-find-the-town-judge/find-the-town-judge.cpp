class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0){
            if(n==1) return 1;
            else{
                return -1;
            }
        }
        vector<int> ind(n+1,0),out(n+1,0);
        for(auto it: trust){
            ind[it[1]]++;
            out[it[0]]++;
        }

        for(int i=0; i<=n; i++){
            if(ind[i]==n-1 && out[i]==0){
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;

        st.insert({0,0});
        int row = 0;
        int col = 0;
        for(int i=0; i<path.size(); i++){
            if(path[i]=='N'){
                int ncol = col+0;
                int nrow = row-1;
                if(st.find({nrow,ncol})!=st.end()){
                    return true;
                }
                row = nrow;
                col = ncol;
                st.insert({row,col});
            }if(path[i]=='S'){
                int ncol = col+0;
                int nrow = row+1;
                if(st.find({nrow,ncol})!=st.end()){
                    return true;
                }
                row = nrow;
                col = ncol;
                st.insert({row,col});
            }if(path[i]=='E'){
                int ncol = col+1;
                int nrow = row+0;
                if(st.find({nrow,ncol})!=st.end()){
                    return true;
                }
                row = nrow;
                col = ncol;
                st.insert({row,col});
            }if(path[i]=='W'){
                int ncol = col-1;
                int nrow = row+0;
                if(st.find({nrow,ncol})!=st.end()){
                    return true;
                }
                row = nrow;
                col = ncol;
                st.insert({row,col});
            }
        }
        return false;
    }
};
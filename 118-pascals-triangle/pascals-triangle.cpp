class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        int ans[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
                }
                
            }
        }

        vector<vector<int>> an;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<=i; j++){
                temp.push_back(ans[i][j]);
            }
            an.push_back(temp);
        }
        return an;
    }
};
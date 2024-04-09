class Solution {
public:
    void solve(int ind, int sum, int k, int n, vector<vector<int>> &ans, vector<int> &temp){
        if(ind==n+1){
           return;
        }

        if(temp.size()==k){
            if(sum==n){
                ans.push_back(temp);
              
            }
            return;
        }

        for(int i=ind; i<=9; i++ ){
            if(sum+i>n) break;
            temp.push_back(i);
            sum += i;
            solve(i+1,sum,k,n,ans,temp);
            sum -= i;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,0,k,n,ans,temp);
        return ans;
    }
};
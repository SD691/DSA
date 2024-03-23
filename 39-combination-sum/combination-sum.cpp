class Solution {
public:

    void helper(int i, int target, vector<int> &cand, vector<int> &temp, vector<vector<int>> &ans){
        if(i==cand.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        
        if(cand[i]<=target){
            temp.push_back(cand[i]);
            helper(i,target-cand[i],cand,temp,ans);
            temp.pop_back();
        }
        helper(i+1,target,cand,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,target, candidates, temp, ans);
        return ans;
    }
};
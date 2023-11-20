class Solution {
public:

    void helper(int ind, int sum, int n, vector<int> &temp, vector<vector<int>> &ans, vector<int> &candidates){
      
            if(sum==0){
                ans.push_back(temp);
                return;
            }

            for(int i = ind; i<candidates.size(); i++){
                if(i>ind && candidates[i]==candidates[i-1]) continue;
                if(candidates[i]>sum) break;
                temp.push_back(candidates[i]);
                helper(i+1,sum-candidates[i],n,temp,ans,candidates);
                temp.pop_back();
            }
           
        

        
       
           
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = target;
        sort(candidates.begin(),candidates.end());
        helper(0,sum,n,temp,ans,candidates);
        return ans;
    }
};
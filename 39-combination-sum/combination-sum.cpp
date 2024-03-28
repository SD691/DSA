class Solution {
public:
    void find(int ind, vector<vector<int>> &ans, vector<int> &temp, vector<int> &arr, int k){
        if(ind==arr.size()){
            if(k==0){
            ans.push_back(temp);
        }
            return;
        }
        

        find(ind+1,ans,temp,arr,k);
        if(arr[ind]<=k){
            temp.push_back(arr[ind]);
            find(ind,ans,temp,arr,k-arr[ind]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(0,ans,temp,candidates,target);
        return ans;
    }
};
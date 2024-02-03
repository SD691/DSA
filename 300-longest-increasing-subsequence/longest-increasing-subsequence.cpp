class Solution {
public:
    int helper(int ind, int pre_idx, vector<int> &nums, vector<vector<int>> &dp){
        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][pre_idx+1]!=-1) return dp[ind][pre_idx+1];
        int notTaken = helper(ind+1,pre_idx,nums,dp);
        int taken = 0;
        if(pre_idx==-1 || nums[ind]>nums[pre_idx]){
            taken = 1+helper(ind+1,ind,nums,dp);
        }
        return dp[ind][pre_idx+1] = max(taken,notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int pre_idx = -1;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,pre_idx,nums,dp);
    }
};
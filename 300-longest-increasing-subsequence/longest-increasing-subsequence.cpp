class Solution {
public:
    int helper(int ind, vector<int> &nums, int &pre_ind, vector<vector<int>> &dp){
        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][pre_ind+1]!=-1) return dp[ind][pre_ind+1];
        int notTaken = 0+helper(ind+1,nums,pre_ind,dp);
        int taken = 0;
        if(pre_ind==-1 || nums[ind]>nums[pre_ind]){
            taken = 1+helper(ind+1,nums,ind,dp);
        }
        return dp[ind][pre_ind+1] = max(taken,notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int pre_ind = -1;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(0,nums,pre_ind,dp);
        
    }
};
class Solution {
public:
    int getAns(vector<int> &nums, int ind,int pre_ind, int n, vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][pre_ind+1]!=-1) return dp[ind][pre_ind+1];

        int notTaken = 0 + getAns(nums,ind+1,pre_ind,n,dp);
        int taken = 0;
        if(pre_ind == -1 || nums[ind]>nums[pre_ind]){
            taken = 1 + getAns(nums,ind+1,ind,n,dp);
        }
        return dp[ind][pre_ind+1] = max(taken,notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
       
        return getAns(nums,0,-1,n,dp);
    }
};
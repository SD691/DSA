class Solution {
public:

    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int pick = f(ind-2,nums,dp) + nums[ind];
        int notpick = f(ind-1,nums,dp)+0;

        return dp[ind] = max(pick,notpick);

    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};
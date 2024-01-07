class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int ind=n-1; ind>-1; ind--){
            for(int prev_idx=ind-1; prev_idx>=-1; prev_idx--){
                int notTaken = 0+dp[ind+1][prev_idx+1];

                int taken = 0;

                if(prev_idx==-1 || nums[ind]>nums[prev_idx]){
                    taken = 1+dp[ind+1][ind+1];
                }
                dp[ind][prev_idx+1] = max(taken,notTaken);

            }
        }
        
        return dp[0][0];
        
    }
};
class Solution {
public:
    int solve(int diff, int left, int right, vector<vector<int>> &dp, vector<int> &nums){
        if(left>=nums.size() || right<=-1 || left>=right){
            return 0;
        }
        if(dp[left][right]!=-1) return dp[left][right];
        int n = nums.size();
        int first_two = 0;
        int last_two = 0;
        int mid_two = 0;
        if(left == 0 && right==nums.size()-1){
            first_two = 1+solve(nums[left]+nums[left+1],left+2,right,dp,nums);
            last_two = 1+solve(nums[right]+nums[right-1],left,right-2,dp,nums);
            mid_two = 1+solve(nums[left]+nums[right],left+1,right-1,dp,nums);
        }
        else{
            if(left<right && left+1<right && diff==nums[left]+nums[left+1]){
                first_two = 1+solve(diff,left+2,right,dp,nums);
            }
            if(right>left && right-1>left && diff==nums[right]+nums[right-1]){
                last_two = 1+solve(diff,left,right-2,dp,nums);
            }
            if(left<right && diff==nums[left]+nums[right]){
                mid_two =1+solve(diff,left+1,right-1,dp,nums);
            }
        }

        return dp[left][right] = max(first_two,max(last_two,mid_two));
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sum = max(sum,nums[0]+nums[1]);
        sum = max(sum,nums[n-1]+nums[n-2]);
        sum = max(sum,nums[0]+nums[n-1]);

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,n-1,dp,nums); 
    }
};
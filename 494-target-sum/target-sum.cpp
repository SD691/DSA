class Solution {
public:
    int helper(int ind, vector<int> &nums, int currentSum, int target) {
        if (ind < 0) {
            return (currentSum == target) ? 1 : 0;
        }

        int taken = helper(ind - 1, nums, currentSum - nums[ind], target);
        int notTaken = helper(ind - 1, nums, currentSum + nums[ind], target);

        return taken + notTaken;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(n - 1, nums, 0, target);
    }
};

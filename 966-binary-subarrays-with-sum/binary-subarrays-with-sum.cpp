class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return summ(nums, goal) - summ(nums, goal - 1);
    }

    int summ(vector<int>& nums, int target) {
        if(target<0) return 0;
        int i = 0, j = 0, sum = 0, ans = 0;
        while (i < nums.size() && j<nums.size()) {
            sum = sum + nums[i];

            while (sum > target) {
                sum = sum - nums[j];
                j++;
            }
            ans = ans + (i - j + 1);
            i++;
        }
        return ans;
    }
};
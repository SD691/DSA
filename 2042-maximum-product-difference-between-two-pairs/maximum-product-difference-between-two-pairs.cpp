class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first = nums[0]*nums[1];

        int last = 1;
        last = last*nums.back();
        nums.pop_back();
        last = last*nums.back();

        return last-first;
    }
};
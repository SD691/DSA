class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        int one = nums.back()-1;
        nums.pop_back();
        int two = nums.back()-1;
        return (one*two);
    }
};
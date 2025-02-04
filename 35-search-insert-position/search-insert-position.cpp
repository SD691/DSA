class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]==target || nums[mid]>target){
                r--;
            }
            else{
                l++;
            }
        }
        return l;
    }
};
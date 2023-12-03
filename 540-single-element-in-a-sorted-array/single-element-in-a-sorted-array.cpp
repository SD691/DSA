class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int l = 0;
        int r = nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        while(l<=r){
            int mid = (l+r)/2;
            if( (mid==nums.size()-1 ||nums[mid]!=nums[mid+1]) && (mid==0 || nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            if(nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    r = mid-2;
                }
                else{
                    l = mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    l = mid+2;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};
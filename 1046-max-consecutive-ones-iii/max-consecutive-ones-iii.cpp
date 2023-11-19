class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int count=0;
        int finall = 0;

        while(r<nums.size() && l<=r){
            if(nums[r]==0){
                count++;
            }

            while(count>k){
                if(nums[l]==0){
                    count--;
                }
                l++;
            }
            finall = max(finall,r-l+1);
            r++;

        }
        return finall;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int count = 0;
        while(i<nums.size()-1){
            count = max(count,nums[i]);
            if(count==0){
                return false;
            }
            count--;
            i++;
        }
        if(i==nums.size()-1){
            return true;
        }
        return false;
    }
};
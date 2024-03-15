class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int sum = 1, zerosum = 1;
        int totalzero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                sum = sum * nums[i];
            }
            zerosum *= nums[i];
            if(nums[i]==0){
                totalzero++;
            }
        }
        if(totalzero==nums.size()){
            return nums;
        }
        if(totalzero>=2){
            vector<int> temp(n,0);
            return temp;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (zerosum == 0) {
                    ans.push_back(zerosum);
                } else {
                    int val = sum / nums[i];
                    ans.push_back(val);
                }

            } else if (nums[i] == 0) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
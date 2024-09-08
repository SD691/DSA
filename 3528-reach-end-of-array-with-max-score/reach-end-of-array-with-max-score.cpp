class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int idx = 0;
        int l = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i]>l){
                long long k = i-idx;
                ans += l*k;
                l = nums[i];
                idx = i;
            }
        }

        long long k = n-1-idx;
        ans+= l*k;
        return ans;
    }
};
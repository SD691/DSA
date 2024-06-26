class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pref = 0;
        int suf = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(pref==0) pref = 1;
            if(suf==0) suf = 1;

            pref *= nums[i];
            suf *= nums[n-i-1];
            ans = max(ans,max(pref,suf));
        }
        return ans;
    }
};
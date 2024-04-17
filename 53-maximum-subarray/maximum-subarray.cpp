class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            pos += nums[i];
            neg += nums[i];

            ans = max(ans,max(pos,neg));
            if(pos<0){
                pos=0;
            } 
        }
        return ans;
    }
};
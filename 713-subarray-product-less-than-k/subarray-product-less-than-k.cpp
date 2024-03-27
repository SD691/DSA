class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        long long int prod=1,ans=0;
        while(i<nums.size()){
            prod = prod*nums[i];

            while(prod>=k && j<nums.size() && j<=i){
                
                prod = prod/nums[j];
                j++;
            }
            if(prod<k){
                ans = ans+(i-j+1);
            }
            i++;
        }
        return ans;
    }
};
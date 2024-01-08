class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n);
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            hash[i]= i;
            for(int prev = 0; prev<i; prev++){
                if((nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0) && dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
            }
        }
        int maxi = -1;
        int update = -1;
        for(int i=0; i<n; i++){
            if(dp[i]>maxi){
                maxi = max(dp[i],maxi);
                update = i;
            }            
        }

        vector<int> temp;
        temp.push_back(nums[update]);
        while(hash[update]!=update){
            update = hash[update];
            temp.push_back(nums[update]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if((nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0) && dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
            }
        }

        int ans = -1;
        int index = -1;
        for(int i=0; i<n; i++){
            if(ans<dp[i]){
                ans = dp[i];
                index = i;
            }
        }

        vector<int> anss;
        anss.push_back(nums[index]);

        while(hash[index]!=index){
            index = hash[index];
            anss.push_back(nums[index]);
        }
        reverse(anss.begin(),anss.end());
        return anss;

    }
};
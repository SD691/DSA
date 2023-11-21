class Solution {
public:

    bool partitionEqualSum(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return arr[ind] == target;
        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTaken = partitionEqualSum(ind-1,target,arr,dp);
        bool taken = false;
        if(arr[ind]<=target){
            taken = partitionEqualSum(ind-1, target-arr[ind], arr,dp);
        }
        return dp[ind][target] = notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = sum+nums[i];
        }

        if(sum%2 != 0){
            return false;
        }
        sum = sum/2;
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return partitionEqualSum(n-1,sum,nums,dp);
    }
};
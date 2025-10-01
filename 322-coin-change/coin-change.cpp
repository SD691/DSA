class Solution {
public:
    int coinChange(vector<int>& arr, int x) {
        // int x = amount;
        int n = arr.size();

        vector<int> dp(x+1,1e9);
        dp[0]=0;
    
        for(int i=1; i<=x; i++){
            for(int j=0; j<n; j++){
                if(arr[j]<=i){
                    dp[i]= min(dp[i],dp[i-arr[j]]+1);
                }
            }
        }
    
        if(dp[x]==1e9){
            return -1;
        }
        return dp[x];
    }
    
};
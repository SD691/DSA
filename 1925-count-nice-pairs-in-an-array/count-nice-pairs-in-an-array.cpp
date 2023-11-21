class Solution {
public:

    int rev(int i){
        int ans = 0;
        while(i!=0){
            ans = ans*10 + i%10;
            i = i/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int count =0;
        for(int i=0; i<n; i++){
            nums[i] = nums[i]-rev(nums[i]);
        }

        int ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<nums.size(); i++){
            ans = (ans+mp[nums[i]])%mod;
            mp[nums[i]]++;
        }


        
        
        return ans;
    }
};
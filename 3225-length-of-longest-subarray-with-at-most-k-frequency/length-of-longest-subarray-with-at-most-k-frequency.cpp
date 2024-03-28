class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        int ans = 0;
        while(i<nums.size()){
            mp[nums[i]]++;

            while(mp[nums[i]]>k && j<nums.size() && j<=i){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }

            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};
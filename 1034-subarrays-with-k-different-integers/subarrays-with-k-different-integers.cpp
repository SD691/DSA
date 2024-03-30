class Solution {
public:
    int diff(vector<int> &nums, int k){
        unordered_map<int,int> mp;

        int total = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            total = total+(r-l+1);
            r++;

        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return diff(nums,k)-diff(nums,k-1);
    }

};
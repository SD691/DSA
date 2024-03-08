class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int maxi = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(maxi<mp[nums[i]]){
                maxi = mp[nums[i]];
            }
        }

        for(auto it: mp){
            if(it.second==maxi){
                sum = sum+it.second;
            }
        }
        
        return sum;
    }
};
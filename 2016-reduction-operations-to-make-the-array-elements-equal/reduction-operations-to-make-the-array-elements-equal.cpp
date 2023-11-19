class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int sum = 0;
      
        map<int,int> mp;

        sort(nums.begin(),nums.end());
       
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int count = mp.size();
        for(auto it: mp){
            int freq = it.second;

            sum = sum + (freq*(mp.size()-count));
            count--;
        }
        return sum;

    }
};
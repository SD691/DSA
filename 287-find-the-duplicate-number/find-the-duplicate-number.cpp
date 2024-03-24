class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int temp = 0;

        unordered_map<int,int>:: iterator itr;
        for(itr = freq.begin(); itr!=freq.end(); itr++){
            if(itr->second >1){
                temp = itr->first;
            }
        }
        return temp;
    }
};
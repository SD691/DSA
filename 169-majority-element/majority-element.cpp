class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                val = nums[i];
            }

            if(val==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return val;
    }
    
};
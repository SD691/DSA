class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sun(nums,k)-sun(nums,k-1);
    }
    int sun(vector<int> &nums, int k){
       
        int j=0;
        int count = 0;
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                count++;
            }
            
            while(count>k){
                if(nums[j]%2!=0){
                    count--;
                }
                j++;
            }
            total += i-j+1;
        }
        return total;
    }
};
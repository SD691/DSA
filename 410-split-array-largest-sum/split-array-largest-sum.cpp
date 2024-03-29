class Solution {
public:
    int bs(vector<int> &nums, int mid){
        int total=0;
        int student=  1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]+total<=mid){
                total += nums[i];
            }
            else{
                student++;
                total = nums[i];
            }
        }
        return student;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for (int i = 0; i < nums.size(); i++) {
            low = max(low,nums[i]);
            high += nums[i]; 
        }
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            int val = bs(nums,mid);

            if(val==k){
                ans = min(ans,mid);
                high = mid-1;
            }
            else if(val>k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
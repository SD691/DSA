class Solution {
public:
    int solve(vector<int> &nums , int mid){
        int total = 0;
        int student =1;
        for(int i=0; i<nums.size(); i++){
            if(total+nums[i]<=mid){
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
        if(nums.size()<k) return -1;
        //sort(nums.begin(),nums.end());
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        

        while(low<=high){
            int mid = (low+high)/2;
            int val = solve(nums,mid);

            if(val>k){
                low=  mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;

    }
};
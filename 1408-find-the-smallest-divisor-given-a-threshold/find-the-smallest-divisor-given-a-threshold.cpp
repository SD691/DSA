class Solution {
public:
    int maxi(vector<int> &nums){
        int maximum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maximum = max(maximum,nums[i]);
        }
        return maximum;
    }
    

    int totalS(vector<int> &nums, int val){
        int n = nums.size();
        int totalsum = 0;
        for(int i=0; i<n; i++){
            totalsum = totalsum + ceil((double)nums[i] / val);
        }
        return totalsum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = maxi(nums);
        while(l<=r){
            int mid = (l+r)/2;
            int total = totalS(nums,mid);
            if(total<=threshold){
                r = mid-1;
            } 
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
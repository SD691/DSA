class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right= height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;

        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]>left_max){
                    left_max = height[left];
                }
                else{
                    water = water + left_max-height[left];
                }
                left++;
            }
            else{
                if(height[right]>right_max){
                    right_max = height[right];
                }
                else{
                    water = water + (right_max-height[right]);
                }
                right--;
            }
        }
        return water;
    }
};
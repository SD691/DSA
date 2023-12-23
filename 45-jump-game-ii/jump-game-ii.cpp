class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int count = 0;
        int curr_dis = nums[0]+0;
        int next_dis = 0;
        int prev_dis = 0;
        int pt = 0;
        int n = nums.size()-1;
        for(int i=1; i<nums.size(); i++){
            if(curr_dis>=n){
                count++;
                break;
            }
            next_dis = nums[i]+i;
            if(curr_dis<next_dis){
                if(pt==0){
                    prev_dis = curr_dis;
                    curr_dis = next_dis;
                    count++;
                    pt++;
                }
                else if(i<=prev_dis){
                    curr_dis = next_dis;
                }
                else{
                    prev_dis = curr_dis;
                    curr_dis = next_dis;
                    count++;
                }
               
            }

        }
        return count;
    }
};
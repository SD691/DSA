class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
               q1.push(nums[i]);
            }
            else{
                q2.push(nums[i]);
            }
        }

        int k = 0;
        while(k<nums.size()){
            if(k%2!=0){
                nums[k] = q1.front();
                q1.pop();
            }
            else if(k%2==0){
               nums[k] = q2.front();
               q2.pop();
            }
            k++;
        }
        return nums;


    }
};
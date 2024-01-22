class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        int dup = -1;
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i])!=st.end()){
                dup = nums[i];
            }
            st.insert(nums[i]);
        }
        int count = 1;
        for(auto it: st){
            if(st.find(count)!=st.end()){
                count++;
            }
            else{
                break;
            }
        }
        return {dup,count};
    }
};
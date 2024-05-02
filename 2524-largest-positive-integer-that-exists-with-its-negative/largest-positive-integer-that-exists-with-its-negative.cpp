class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int ans = -1;
        for(auto it: st){
            if(st.find(-it)!=st.end()){
                ans = max(ans,abs(it));
            }
        }
        return ans;
    }
};
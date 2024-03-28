class Solution {
public:
    void find(int ind, vector<int> &temp, set<vector<int>> &st,vector<int> &nums){
        if(ind==nums.size()){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        find(ind+1,temp,st,nums);

        temp.pop_back();
        find(ind+1,temp,st,nums);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        set<vector<int>> st;
        vector<vector<int>> ans;
        find(0,temp,st,nums);
        for(auto it: st){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
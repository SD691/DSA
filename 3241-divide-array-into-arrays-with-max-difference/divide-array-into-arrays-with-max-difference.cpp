class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        int j = i + 1;
        temp.push_back(nums[i]);

        while (i < nums.size() && j < nums.size()) {
            if (temp.size() == 3) {
                ans.push_back(temp);
                temp.clear();
                i = j;
                temp.push_back(nums[i]);
                j = i + 1;
            } else if (abs(nums[i] - nums[j]) <= k) {
                temp.push_back(nums[j]);
                j++;
            } else {
                return {};
            }
        }

        
        if (!temp.empty()) {
            ans.push_back(temp);
        }

        if (ans.size() * 3 == nums.size()) {
            return ans;
        }
        return {};
    }
};
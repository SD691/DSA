class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(0);
        int j = 0;
        for(int i=1; i<n; i++){
            if(nums[i]%2==nums[i-1]%2){
                j++;
            }
            arr.push_back(j);
        }

        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            
                if(arr[queries[i][0]]==arr[queries[i][1]]){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
        }
        return ans;
   }
};
class Solution {
public:
    
    string getPermutation(int n, int k) {
         vector<int> nums;
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        
        while(k > 1) { // If k=1, it's already in the correct permutation
            next_permutation(nums.begin(), nums.end());
            k--;
        }

        string fin;
        for(int i = 0; i < nums.size(); i++) {
            fin += to_string(nums[i]);
        }
        return fin;

    }
};
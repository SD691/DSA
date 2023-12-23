class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps = 0, currEnd = 0, currFarthest = 0;

        for(int i = 0; i<n-1; i++){

            currFarthest = max(currFarthest, i+nums[i]);

            if(i==currEnd){
                jumps++;
                currEnd = currFarthest;
            }
        }
        return jumps;
    }

    /*the intution behing this solution is
    travel the distance equivalent to the value of the i+nums[i]
    now when we reach that distance 
    then we are going to find which element can take us to the futher element
    this we are going to figure out from currfarthest.
    thus eventually we will reach the end adn will return the jumos*/
};
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_count = 0;
        int ans = 0;

        for(auto it: bank){
            int current_count = 0;

            for(char c: it){
                if(c == '1'){
                    current_count++;
                }
            }
            if(current_count>0){
                ans += prev_count*current_count;
                prev_count = current_count;
            }
        }
        return ans;
    }
};
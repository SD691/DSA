class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> no_of_one;
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(count>0){
                no_of_one.push_back(count);
            }
        }
        int ans = 0;
        if(no_of_one.size()<=1) return 0;
        for(int i=1; i<no_of_one.size(); i++){
            ans = ans + (no_of_one[i]*no_of_one[i-1]);
        }
        return ans;
    }
};
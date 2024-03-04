class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int score = 0;
        int i=0;
        int j = token.size()-1;
        int ans = 0;
        while(i<=j){
            if(power>=token[i]){
                power -= token[i];
                score++;
                i++;
                ans = max(ans,score);
            }
            else if(power<token[i] && score>0){
                power = power+token[j];
                j--;
                score--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
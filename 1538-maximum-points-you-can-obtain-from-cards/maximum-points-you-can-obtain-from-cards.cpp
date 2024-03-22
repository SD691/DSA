class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int ans = 0;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
            ans = max(ans,sum);
        }

        int i=k-1;
        int j=cardPoints.size()-1;
        while(i>-1 && j>-1){
            sum -= cardPoints[i];
            sum += cardPoints[j];
            ans = max(ans,sum);
            i--;
            j--;
        }
        return ans;
    }
};
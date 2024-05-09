class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        sort(happiness.begin(),happiness.end());
        int c= 0;
        while(c<k){
            if(c==0){
                sum += happiness.back();
                happiness.pop_back();
            }
            if(c>0){
                int val = happiness.back();
                happiness.pop_back();
                val -= c;
                if(val<0){
                    val = 0;
                    break;
                }
                sum += val;
            }
            c++;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> a;
        for(int i=1; i<=9; i++){
            int val = i;
            int nextDigit = i+1;

            while(val<=high && nextDigit<=9){
                val =val*10+nextDigit;
                if(val>=low && val<=high){
                    a.push_back(val);
                }
                nextDigit++;
            }
        }

        sort(a.begin(),a.end());
        return a;
    }
};
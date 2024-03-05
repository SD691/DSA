class Solution {
public:
long long  mod = INT_MAX;
    bool judgeSquareSum(int c) {
        c= c%mod;
        int n = sqrt(c);
        int i=0;
        int j=n;
        while(i<=j){
            long long int val = (i*i)%mod+(j*j)%mod;
            if(val== c){
                return true;
            }
            else if(val>c){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
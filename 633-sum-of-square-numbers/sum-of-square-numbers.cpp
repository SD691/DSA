class Solution {
public:
long long  mod = INT_MAX;
    bool judgeSquareSum(int c) {
        
        long long n = sqrt(c);
        long long i=0;
        long long j=n;
        while(i<=j){
            long long int val = (i*i)+(j*j);
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
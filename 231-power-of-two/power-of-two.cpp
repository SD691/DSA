class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==2) return true;
        if(n==4) return true;
        if(n>=4){
            long long i = 2;
            while(i<=n){
                if(i==n) return true;
                i= i*2;
            }
            //if(i==n) return true;
            
        }
        return false;
    }
};
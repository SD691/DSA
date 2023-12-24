class Solution {
public:
    bool isPowerOfTwo(int n) {
        // bit manipulation of a power of 2 number and one less of that number will give us 0 as answer in bits, thus this is the approach we are going to use

        if(n>0 && (n&(n-1))==0) return true;
        return false;
    }
};
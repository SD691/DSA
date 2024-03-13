class Solution {
public:
    int pivotInteger(int n) {
        double x = sqrt(n*(n+1)/2.0);
        int intPart = static_cast<int>(x);
        if(x-intPart!=0){
            return -1;
        }
        else{
            return static_cast<int>(x);
        }
    }
};
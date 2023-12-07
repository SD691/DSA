class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int sum =0;
        for(int i=0; i<piles.size(); i++){
            sum = max(sum,piles[i]);
        }

        long l=1;
        long r =sum;
        while(l<=r){
            long mid = (l+r)/2;
            long long int count = 0;
            
            for(int i=0; i<piles.size(); i++){
                count = count + ceil((double)(piles[i])/(double)(mid));
            }

            if(count>h){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;

    }
};
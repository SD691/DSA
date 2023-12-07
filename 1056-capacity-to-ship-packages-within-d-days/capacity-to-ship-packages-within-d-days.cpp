class Solution {
public:
    int shipWithinDays(vector<int>& weights, int givenDays) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);


        int ans = INT_MAX;

        while(l<=r){
            int mid = (l+r)/2;
            int days = 1;
         
            int load = 0;

           for (int i = 0; i < weights.size(); i++) {
                if (load + weights[i] > mid) {
                        days += 1; //move to next day
                        load = weights[i]; //load the weight.
                    }
                else {
                        //load the weight on the same day.
                        load += weights[i];
                    }
            }
            

            if(days<=givenDays){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
           
        }
        return l;
    }
};
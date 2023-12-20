class Solution {
public:

    int buyChoco(vector<int>& prices, int money) {
        int original = money;
        sort(prices.begin(),prices.end());
        money = money-(prices[0]+prices[1]);
        if(money>-1){
            return money;
        }
        return original;
    
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                ten++;
                if(five>=1){
                    five--;
                }
                else{
                    return false;
                    break;
                }
            }
            else if(bills[i]==20){
                twenty++;
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five = five - 3;
                }
                else{
                    return false;
                    break;
                }
            }
        }
        return true;
        
    }
};
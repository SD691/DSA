class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        double count = arr.size()/4;
        int count_num = 1;

        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]){
                count_num++;
            }
            else{
                count_num = 1;
            }
            if(count_num>count){
                return arr[i];
                break;
            }
        }
        return 0;
    }
};
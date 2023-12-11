class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        double count = arr.size()/4;
        unordered_map<int,int> mp;

        for(auto it: arr){
            mp[it]++;
        }

        for(auto it: mp){
            if(it.second>count){
                return it.first;
                break;
            }
        }
        return 0;
    }
};
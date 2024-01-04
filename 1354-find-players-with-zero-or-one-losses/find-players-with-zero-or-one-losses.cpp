class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win,los;

        for(int i=0; i<matches.size(); i++){
            win[matches[i][0]]++;
            los[matches[i][1]]++;
        }

        vector<int> winn,loss;
        for(auto it: win){
            if(los.find(it.first)==los.end()){
                winn.push_back(it.first);
            }
        }
        sort(winn.begin(),winn.end());

        for(auto it: los){
            if(it.second==1){
                loss.push_back(it.first);
            }
        }

        sort(loss.begin(),loss.end());

        return {winn,loss};
    }
};
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1) return true;


        unordered_map<int,int> mp;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                mp[words[i][j]]++;
            }
        }

        int count = words.size();
      
        for(auto it: mp){
            if(it.second%count!=0){
                return false;
            }
                
        }
        return true;
    }
};
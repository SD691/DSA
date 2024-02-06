class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            string put = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(put);
        }

        vector<vector<string>> ans;
        
        for(auto it: mp){
            vector<string> anst;
            for(auto itr: it.second){
                anst.push_back(itr);
            }
            ans.push_back(anst);
            
        }
        return ans;
    }
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,string> mp;
        vector<string> sec;

        int n = paths.size();
        int m = paths[0].size();
        for(int i=0; i<n; i++){
           mp[paths[i][0]] = paths[i][1];
           sec.push_back(paths[i][1]);
        }
        string ans;
        int count = 0;
        for(int i=0; i<sec.size(); i++){
            if(mp.find(sec[i])!=mp.end()){
                count++;
            }
            else{
                ans = sec[i];
                break;
            }
        }
        return ans;
    }
};
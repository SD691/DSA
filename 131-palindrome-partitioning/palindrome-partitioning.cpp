class Solution {
public:
    bool palin(string temp){
        int n = temp.size();
        for(int i=0; i<temp.size()/2; i++){
            if(temp[i]!=temp[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(int ind, string s, vector<vector<string>> &ans, vector<string> &temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            string temp_string;
            for(int j=ind; j<=i; j++){
                temp_string.push_back(s[j]);
            }
            if(palin(temp_string)){
                temp.push_back(temp_string);
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,ans,temp);
        return ans;
    }
};
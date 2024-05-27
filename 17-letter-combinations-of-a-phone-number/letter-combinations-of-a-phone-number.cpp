class Solution {
public:

    void solve(int ind, string s, vector<string> &ans,unordered_map<char,string> &mp, string &temp){
        if(ind==s.size()){
            if(temp.size()>0){
                ans.push_back(temp);
            }
            
            return;
        }

        for(auto it:mp[s[ind]]){
            temp.push_back(it);
            solve(ind+1,s,ans,mp,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp;
        solve(0,digits,ans,mp,temp);
        
        return ans;
    }
};
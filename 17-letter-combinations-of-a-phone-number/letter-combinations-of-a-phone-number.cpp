class Solution {
public:

    void helper(string &digits, int start, string &temp, vector<string> &ans, map<int,string> mp){
        if(start == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(auto it: mp[digits[start]-'0']){
            temp.push_back(it);
            helper(digits,start+1,temp,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        map<int,string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string temp;
        vector<string> ans;
        helper(digits,0,temp,ans,mp);
        return ans;
    }
};
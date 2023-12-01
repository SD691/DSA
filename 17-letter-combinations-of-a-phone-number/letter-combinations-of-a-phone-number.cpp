class Solution {
public:
    vector<string> ans;
    map<int,string> mp;
    void helper(string &digits, int start, string&temp){
        if(start == digits.size()){
            ans.push_back(temp);
        }

        for(auto it: mp[digits[start]-'0']){
            temp.push_back(it);
            helper(digits,start+1,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
       
        if(digits==""){
            return ans;
        }

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp;
        helper(digits,0,temp);
        return ans;
    }
};
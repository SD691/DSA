class Solution {
public:
    bool helper(int ind, string s, unordered_map<string,int> &mp, vector<int> &dp){
        if(ind==s.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        string a = "";
        for(int i=ind; i<s.size(); i++){
            a = a+s[i];
            if(mp[a]){
                if(helper(i+1,s,mp,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;

        for(auto it: wordDict){
            mp[it]++;
        }
        vector<int> dp(s.size(),-1);
        return helper(0,s,mp,dp);
    }
};
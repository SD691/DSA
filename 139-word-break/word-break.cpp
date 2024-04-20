class Solution {
public:
    bool find(int ind, string s, unordered_map<string,int> &mp, vector<int> &dp){
        if(ind==s.size()){
            return true;
        }

        if(dp[ind]!=-1) return dp[ind];
        string temp;
        for(int i=ind; i<s.size(); i++){
            temp += s[i];
            if(mp.find(temp)!=mp.end()){
                if(find(i+1,s,mp,dp)==true){
                    return dp[ind]= true;
                }
            } 
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        vector<int> dp(s.size()+1,-1);
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }

        return find(0,s,mp,dp);
    }
};
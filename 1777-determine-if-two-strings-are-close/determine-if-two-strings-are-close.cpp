class Solution {
public:
    bool check(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        map<char,int> mp1,mp2;
        for(auto it: word1){
            mp1[it]++;
        }
        for(auto it: word2){
            mp2[it]++;
        }
        map<int,int> mp;
        for(auto it: mp1){
            mp[it.second]++;
        }
        int n= mp.size();
        for(auto it: mp2){
            mp[it.second]++;
        }
        if(n!=mp.size()) return false;
        for(auto it: mp){
            if(it.second%2!=0){
                return false;
            }
        }
        return true;
    }

    bool two(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        map<char,int> mp,mp2,mp1;
        for(auto it: word1){
            mp[it]++;
            mp1[it]++;
        }
        int n = mp.size();
        for(auto it: word2){
            mp[it]++;
            mp2[it]++;
        }
        if(mp.size()!=n || mp1.size()!=mp2.size()){
            return false;
        }
        return true;

    }

    bool closeStrings(string word1, string word2) {
        if(check(word1,word2)==true && two(word1,word2)==true) return true;
        return false;
    }
};
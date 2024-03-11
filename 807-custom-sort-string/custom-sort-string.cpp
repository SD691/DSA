class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        string ans;
        for(int i=0; i<order.size(); i++){
            if(mp.find(order[i])!=mp.end()){
                while(mp[order[i]]){
                    ans = ans+order[i];
                    mp[order[i]]--;
                }
            }
            if(mp[order[i]]==0){
                mp.erase(order[i]);
            }
        }

        for(auto it: mp){
            while(it.second!=0){
                ans = ans+it.first;
                it.second--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSpecialChars(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        for(int i=s.size()-1; i>-1; i--){
            if(s[i]>='a' && s[i]<='z'){
                if(mp.find(s[i])==mp.end()){
                    mp[s[i]]= i;
                }
            }
            else{
                mp[s[i]] = i;
            }    
        }

        for(int i=0; i<s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                if(mp.find(s[i]+32) !=mp.end() && mp[s[i]+32]<mp[s[i]]){
                    ans++;
                    mp[s[i]]=s.size()-1;
                    mp[s[i]+32] = s.size()-1;
                }
            }
        }
        return ans;

    }
};
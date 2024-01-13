class Solution {
public:
    int minSteps(string s, string t) {
        int mp[26] = {0};  // Initialize to zero
        int mp2[26] = {0};  // Initialize to zero

        for(int i = 0; i < s.size(); i++){
            mp[s[i] - 'a']++;
            mp2[t[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0 && mp2[i] > 0){
                if(mp[i] == mp2[i]){
                    ans = ans + mp[i];
                }
                else{
                    ans = ans + min(mp[i],mp2[i]);
                }
            }
        }
        return s.size() - ans;
    }
};

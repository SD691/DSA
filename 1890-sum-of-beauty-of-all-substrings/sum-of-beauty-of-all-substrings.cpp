class Solution {
public:
    int beautySum(string s) {
        unordered_map<int,int> mp;
        
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                mp[s[j]]++;
                int maxi = 0;
                int mini = INT_MAX;
               for(auto it: mp){
                maxi = max(maxi,it.second);
                mini = min(mini,it.second);
               }
                ans += maxi-mini; 
            }

            mp.clear();
        }
        return ans;
    }
};
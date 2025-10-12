class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans = 0;
        map<char,int> mp;
        set<int> st;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                mp[s[j]]++;
                // cout<<"mp[s[i]]-> "<<s[i]<<" "<<mp[s[i]]<<endl;
                int mini=INT_MAX;
                int maxi= INT_MIN;
               for(auto it: mp){
                    mini= min(mini,it.second);
                    maxi = max(maxi,it.second);
               }
                
                if(mini==maxi){
                    ans = max(ans,j-i+1);
                }
                
            }
            
            mp.clear();
        }
        return ans;
    }
};
class Solution {
public:
    bool compare(string a, string b ){
        if(a.size()!=b.size()+1) return false;

        int i = 0,j = 0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else if(a[i]!=b[j]){
                i++;
            }
        }
        if(i==a.size() && j==b.size()){
            return true;
        }
        return false;
    }
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = -1;
        sort(words.begin(),words.end(),comp);
        for(int i=0; i<n; i++){

           //sort(words[i].begin(),words[i].end());

            for(int prev = 0; prev<i; prev++){
                //sort(words[prev].begin(),words[prev].end());

                if(compare(words[i],words[prev]) && dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;   
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;   
    }
};
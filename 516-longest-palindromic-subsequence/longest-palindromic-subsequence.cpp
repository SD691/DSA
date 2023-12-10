class Solution {
public:

    bool ispalindrom(string &st){
        int right = st.size()-1;
        int left = 0;
        while(left<right){
            if(st[left]!=st[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void helper(int ind, string &st, string s, int &ans){
        if(ind==s.size()){
            return;
        }

        st = st+s[ind];
        if(ispalindrom(st)){
            int size = st.size();
            ans = max(ans,size);
            helper(ind+1,st,s,ans);
           
        }
        st.pop_back();
        helper(ind+1,st,s,ans);
    }
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());

        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0; i<n; i++) {
            dp[0][i];
            dp[i][0];
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0+ max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];


        
    }
};
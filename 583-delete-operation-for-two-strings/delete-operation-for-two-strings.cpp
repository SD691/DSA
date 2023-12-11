class Solution {
public:
int longestSubsequence(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) 
            return 0;

        if(dp[ind1][ind2]!=-1) 
            return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2]) 
            return dp[ind1][ind2] = 1 + longestSubsequence(s1,s2,ind1-1,ind2-1,dp);
        else
            return dp[ind1][ind2] = 0 + max(longestSubsequence(s1,s2,ind1-1,ind2,dp),longestSubsequence(s1,s2,ind1,ind2-1,dp));
        
    }

   

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return longestSubsequence(text1,text2,n-1,m-1,dp);
    }

    int minDistance(string word1, string word2) {
        int ans = longestCommonSubsequence(word1,word2);
        int n = word1.size();
        int m = word2.size();
        int original = ans;
        int fin = 0;
        fin = n-ans;
        fin = fin + m-ans;
        return fin;
    }
};
class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j = s.size()-1;
        int ans = INT_MAX;
        while(i<j){
            if(s[i]!=s[j]){
                ans = min(ans,j-i+1);
                break;
            }
           while(s[i]==s[j] && i<j){
               i++;
           }
           i=i-1;
           while(s[i]==s[j] && i<j){
               j--;
           }
           i++;
        }
        if(i<s.size() && j>-1 && i==j){
            return 1;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};
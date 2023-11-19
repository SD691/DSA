class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r = 0;
        set<char> st;
        int finall = 0;
        while(r<s.size() && l<=r){
            if(st.find(s[r])!=st.end() && l<=r){
                st.erase(s[l]);
                l++;
            }
            else{
                st.insert(s[r]);
                finall = max(finall,r-l+1);
                r++;
            }
            
            
        }
        return finall;
    }
};
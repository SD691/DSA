class Solution {
public:
    int numberOfSpecialChars(string s) {
        set<char> st(s.begin(),s.end());
        
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                if(st.find(s[i]-32)!=st.end()){
                    ans++;
                    st.erase(s[i]-32);
                }
            }
        }
        return ans;
        
    }
};
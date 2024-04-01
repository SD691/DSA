class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char> st;
        for(int i=s.size()-1; i>-1; i--){
            if(s[i]==' ' && st.empty()){
                continue;
            }
            else if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
                st.push(s[i]);
            }
            else if(s[i]==' ' && !st.empty()){
                break;
            }
        }

        while(!st.empty()){
            return st.size();
        }
        return 0;
    }
};
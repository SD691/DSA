class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string t;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                t.push_back(s[i]);
            }
            else if(s[i]==' '){
                if(t.size()>0){
                    st.push(t);
                    t.clear();
                }
            }
        }

        if(t.size()!=0){
            st.push(t);
        }

        string ans;
        while(!st.empty()){
            ans = ans+st.top()+' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
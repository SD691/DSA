class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return "";
        stack<string> st;
        string temp;
        for(int i=0; i<s.size(); i++){
           
            if(s[i]==' '){
                if(temp.size()!=0){
                    st.push(temp);
                }
                
                temp.clear();
            }
            else if(s[i]!=' '){

                temp.push_back(s[i]);
            }
        }
        st.push(temp);

        string ans;
        while(!st.empty()){
            string tem = st.top();
            if(tem.size()!=0){
                ans= ans+tem+" ";
            }
            
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
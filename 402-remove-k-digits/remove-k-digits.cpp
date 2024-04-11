class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        if(num.length()<=k){
            return "0";
        }

        if(k==0){
            return num;
        }
        for(int i=1; i<num.size(); i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size()==1 && st.top()=='0'){
                st.pop();
            }
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};
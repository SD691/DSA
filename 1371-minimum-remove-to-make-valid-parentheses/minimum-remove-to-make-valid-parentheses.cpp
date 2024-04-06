class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                if(open==0){
                    s[i]='*';
                }
                else{
                    open--;
                }
            }
        }

        for(int i=s.size(); i>-1; i--){
            if(open>0 && s[i]=='('){
                open--;
                s[i]='*';
            }
        }

        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='*'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
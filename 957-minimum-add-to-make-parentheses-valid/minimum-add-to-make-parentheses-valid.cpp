class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int req = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                if(open>0){
                    open--;
                }
                else if(open<=0){
                    req++;
                }
            }
        }

        if(open>0){
            req = open+req;
        }
        return req;
    }
};
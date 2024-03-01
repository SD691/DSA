class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        int n = s.size();
        ans.resize(n,'0');
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                one++;
            }
        }

        if(one==0){
            return ans;
        }
        if(one==1){
            ans[n-1]='1';
            return ans;
        }
        for(int i=0; i<one-1; i++){
            ans[i]= '1';
        }
        ans[n-1] = '1';
        return ans;
    }
};
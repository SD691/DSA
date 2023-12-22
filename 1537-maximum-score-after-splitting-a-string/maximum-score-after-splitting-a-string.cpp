class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        int zero = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                zero++;
            }
            else if(s[i]=='1'){
                one++;
            }
        }

        int ans = 0;
        int z = 0;
        int o = 1;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0'){
                z++;
            }
            else if(s[i]=='1'){
                one--;
            }

            ans = max(ans,(z+one));

        }
        return ans;
    }
};
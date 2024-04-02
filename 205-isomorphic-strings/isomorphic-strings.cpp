class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int ma = t.size();

        if(n!=ma)return false;
        int m1[256] = {0}; // declare character array
        int m2[256] = {0};
        
        for(int i=0; i<s.size(); i++){
            if(!m1[s[i]] && !m2[t[i]]){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m1[s[i]]!=t[i]){
                return false;
            }
        }

        return true;  
    }
};
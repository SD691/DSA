class Solution {
public:
    int count(string s){int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                count++;
            }
        }
        return count;
        }

    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = n/2;

        string a = s.substr(0,mid);
        string b = s.substr(mid,mid);
        if(count(a) == count(b)) return true;
        return false;

    }


};
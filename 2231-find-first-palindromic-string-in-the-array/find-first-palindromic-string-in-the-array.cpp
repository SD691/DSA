class Solution {
public:
    bool isPalin(string s){
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            if(isPalin(words[i])==true){
                return words[i];
            }
        }
        return "";
    }
};
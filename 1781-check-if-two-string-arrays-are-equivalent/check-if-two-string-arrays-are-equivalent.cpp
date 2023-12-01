class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
      

        string str1;
        string str2;
        for(int i=0; i<word1.size(); i++){
            str1 = str1+word1[i];
        }

        for(int i=0; i<word2.size(); i++){
            str2 = str2+word2[i];
        }

        if(str1.size()!=str2.size()){
            return false;
        }

        for(int i=0; i<str1.size(); i++){
            if(str1[i]!=str2[i]){
                return false;
                break;
            }
        }
        return true;

    }
};
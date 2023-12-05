class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> mp;
        int n = s.size();
        int l = 0;
        int r = 0;
        int final = 0;
        int maxC = 0;


        while(r<n){
            mp[s[r]]++; // storing values in map mp
            maxC = max(maxC,mp[s[r]]); // take count of the maximum occured element in map
            int currlen = r-l+1; // to calculate the currlen of the string
            if(currlen-maxC>k){ // if (total length - max repeating element) is greater than k i.e.
                                // if 5-3 = 2  and k is 1, i.e there are 3 different character in the string and we can only replace ..                                  2 so, 1 character is extra
                mp[s[l]]--;     // delete the starting element
                l++;            // increment l
            }
            currlen = r-l+1;       // again calculate the currlen
            final = max(final,currlen); // calculate the length after removing the extra character
            r++;                    // increment r
        }

        return final;               // output the final as answer.
        
    }
};
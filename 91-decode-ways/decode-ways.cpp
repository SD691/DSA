class Solution {
public:
int numDecode(string s, int index, vector<int>& memo){
    if(index == s.size()){
        return 1;
    }

    if(s[index]=='0'){
        return 0;
    }

    if (memo[index] != -1) {
        return memo[index];
    }

    int ways = numDecode(s,index+1,memo);
    if(index+1<s.size() && (s[index]=='1' || (s[index]=='2' && s[index+1]<='6'))){
        ways += numDecode(s,index+2,memo);
    }
    memo[index] = ways;
    return ways;
}
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return numDecode(s,0,memo);
    }
};
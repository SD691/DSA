class Solution {
public:

    int totalSum(int x, int y){
        string a = to_string(x);
        string b = to_string(y);
        int n = a.size();
        int m = b.size();
        int maxLen = max(n,m);

        while(n<maxLen){
            a = "0"+a;
            n++;
        }

        while(m<maxLen){
            b = "0"+b;
            m++;
        }

        int diff = 0;
        unordered_map<char,int> mp1,mp2;
        for(int i=0; i<maxLen; i++){
            diff += (a[i]!=b[i]);
            mp1[a[i]]++;
            mp2[b[i]]++;
        }

        return diff<=2 && mp1==mp2;
    }
    int countPairs(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                count += totalSum(nums[i],nums[j]);
            }
        }
        return count;
    }
};
class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void helper(int idx, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                helper(i + 1, s, temp, ans);
                temp.pop_back(); // Backtrack and remove the last element from temp
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        helper(0, s, temp, ans);
        return ans;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
       if (s.size() != goal.size()) return false;

        string to = s + s;

        for (int i = 0; i < s.size(); i++) {
            int j = 0;
            vector<char> ans;

            while (j < goal.size() && to[i] == goal[j]) {
                ans.push_back(to[i]);
                i++;
                j++;
            }

            if (j == goal.size()) {
                return true;
            }

            // Reset i to the beginning of s, consider the next possible rotation
            i -= ans.size();
        }

        return false;
    }
};
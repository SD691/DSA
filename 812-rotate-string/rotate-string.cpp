class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()){
            return false;
        }
        s = s+s;
        bool val = s.find(goal)!=string::npos;
        return val;
    }
};
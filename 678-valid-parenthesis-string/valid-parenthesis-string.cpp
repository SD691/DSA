class Solution {
public:
    bool checkValidString(string s) {
        
            int n = s.size();

            int left = 0, right = 0, star = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    left++;
                else if (s[i] == ')')
                    right++;
                else
                    star++;

                if (right > star + left)
                    return false;
            }
           	// bool left_checking=true;
            left = 0, right = 0, star = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '(')
                    left++;
                else if (s[i] == ')')
                    right++;
                else
                    star++;

                if (left > star + right)
                    return false;
            }

            return true;
        }
    
};
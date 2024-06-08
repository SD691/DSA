
class Solution {
public:
    int area(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = 0;
            } else {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i > -1; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n - 1;
            } else {
                right[i] = st.top() - 1;
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val = (right[i] - left[i] + 1) * heights[i];
            ans = max(ans, val);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> vec(n, 0);
        int fin = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                if (matrix[i][j] == '1') {
                    vec[j]++;
                } else {
                    vec[j] = 0;
                }
            }
            fin = max(fin, area(vec));
        }
        return fin;
    }
};


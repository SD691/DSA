class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        

        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty() || st.top() < 0 || asteroids[i] > -1) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 && abs(asteroids[i]) > abs(st.top())) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                } else if (abs(asteroids[i]) == abs(st.top())) {
                    st.pop();
                }
            }
        }

        std::vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
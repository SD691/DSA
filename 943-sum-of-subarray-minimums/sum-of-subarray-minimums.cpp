class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int ans= 0;


        for(int i=0; i<=arr.size(); i++){
            while(!st.empty() && (i==arr.size() || arr[st.top()]>arr[i])){
                int mid = st.top();
                st.pop();
                int left = -1;
                if(!st.empty()){
                    left = st.top();
                }
                int right = i;
                
                long long int val = ((mid-left)%mod*(right-mid)%mod)%mod;
                val = (val*arr[mid])%mod;
                ans = (ans+val)%mod;
            }
            st.push(i);
        }
        return ans;
    }
};
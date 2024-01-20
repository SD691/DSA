class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1000000007;

        stack<int> st;
        long long sum = 0;

        for(int i=0; i<=arr.size(); i++){
            while(!st.empty() && (i==arr.size() || arr[st.top()]>=arr[i])){

                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1: st.top();
                int right = i;
                long long int count = ((mid-left)*(right-mid))%mod;

                sum = sum+(count*arr[mid])%mod;
                sum = sum%mod;
            }
            st.push(i);
        }
        return sum;
    }
};
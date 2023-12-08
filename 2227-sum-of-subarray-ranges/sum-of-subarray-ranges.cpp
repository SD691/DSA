class Solution {  // this cod etime complexity is O(N2)
public:
    long long subArrayRanges(vector<int>& nums) {

        long long count  = 0;
        long long sum = 0;
        stack<int> st;
        for(int i=0; i<=nums.size(); i++){
            while(!st.empty() && (i==nums.size() || nums[st.top()]>=nums[i])){

                int mid = st.top();
                st.pop();
                int right = i;
                int left;
                if(!st.empty()){
                    left = st.top();
                }
                else{
                    left = -1;
                }

                count = ((mid-left)*(right-mid));
                sum -=(count*nums[mid]);
            }
            st.push(i);
        }

        count = 0;
        st.pop();

        for(int i=0; i<=nums.size(); i++){
            while(!st.empty() && (i==nums.size() || nums[st.top()]<=nums[i])){
                int mid = st.top();
                st.pop();
                int right = i;
                int left;
                if(!st.empty()){
                    left = st.top();
                }
                else{
                    left = -1;
                }

                count = ((mid-left)*(right-mid));
                sum += count*nums[mid];
            }
            st.push(i);
        }
        return sum;
    }
    
}; 
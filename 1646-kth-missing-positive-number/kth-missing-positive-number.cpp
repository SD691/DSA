class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int r = arr.size()-1;
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]-mid-1<k){
                l++;
            }
            else{
                r--;
            }
        }
        return l+k;
    }
};
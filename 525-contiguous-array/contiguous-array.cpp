class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                count--;
            }
            else{
                count++;
            }
            if(count==0){
                ans = max(ans,i+1);
            }
            if(mp.find(count)!=mp.end()){
                ans = max(ans,i-mp[count]);
            }
            else{
                mp[count] = i;
            }
            
            
        }
        return ans;
    }
};
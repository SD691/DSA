class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;
        for(auto it:mp){
            
            
            int val = it.second;
            if(val==1) return -1;
            while(val>=3){
                if(val%3==0){
                    ans = ans+val/3;
                    break;
                }
                else{
                    ans = ans+1;
                    val = val-2;
                }
            }
            if(val>0 && val<3 && val%2==0){
                ans = ans+val/2;
            }
           

            
            
        }
        
        return ans;
    }
};
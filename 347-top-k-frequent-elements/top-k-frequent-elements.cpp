class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> pq;

       unordered_map<int,int> mp;
       for(int i=0; i<nums.size(); i++){
           mp[nums[i]]++;
       }

       for(auto it: mp){
           pq.push({it.second,it.first});
       }
        vector<int> ans;
       while(!pq.empty()){
           if(k==0) break;
           ans.push_back(pq.top().second);
           pq.pop();
           k--;
       }

       return ans;
    }
};
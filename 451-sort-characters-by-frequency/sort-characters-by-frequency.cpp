class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        string ans;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto itr = pq.top();
            pq.pop();
            while(itr.first!=0){
                ans.push_back(itr.second);
                itr.first--;
            }
        }
        return ans;
    }
};
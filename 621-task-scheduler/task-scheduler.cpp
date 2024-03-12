class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }

        unordered_map<char,int> mp;
        for(auto it: tasks){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }

        
        int ans = 0;
        while(!pq.empty()){
            if(pq.top().first==1){
                ans = ans+pq.size();
                break;
            }
            vector<pair<int,char>> v;
            v.push_back(pq.top());
            pq.pop();
            ans++;
            for(int i=0; i<n; i++){
                if(pq.size()>0){
                    v.push_back(pq.top());
                    pq.pop();
                    
                }
                ans++;
            }

            for(auto it:v){
                if(it.first>1){
                    pq.push({it.first-1,it.second});
                }
            }
        }
        return ans;
    }
};
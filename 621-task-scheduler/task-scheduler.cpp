class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();

        unordered_map<char,int> mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
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
            ans = ans+1;
            for(int i=0; i<n; i++){
                if(pq.size()>0){
                    v.push_back(pq.top());
                    pq.pop();
                }
                ans++;
            }

            for(auto it: v){
                if(it.first>1){
                    pq.push({it.first-1,it.second});
                }
            }
           
        }
         return ans;
    }
};
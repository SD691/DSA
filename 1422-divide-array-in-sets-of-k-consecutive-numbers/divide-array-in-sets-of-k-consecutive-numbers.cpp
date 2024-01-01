class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        for(int i=0; i<hand.size(); i++){
            mp[hand[i]]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
       
        for(auto it: mp){
            pq.push(it.first);
        }
        
        while(!pq.empty()){
            vector<int> ans;
            for(int i=0; i<groupSize; i++){
                if(!pq.empty()){
                    ans.push_back(pq.top());
                    pq.pop();
                }    
            }

            for(int i=0; i<ans.size(); i++){
                mp[ans[i]]--;
                if(mp[ans[i]]>0){
                    pq.push(ans[i]);
                }
            }
            
            if(ans.size()==groupSize){
                for(int i=0; i<ans.size()-1; i++){
                    if(ans[i+1]-ans[i]!=1){
                        return false;
                    }
                }
            }
            else{
                return false;
            }
           
            
        }
        return true;
    }
};
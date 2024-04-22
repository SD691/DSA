class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;

        q.push({"0000",0});
        unordered_set<string> deadendSet(deadends.begin(),deadends.end());
        unordered_map<string,int> vis;
        vis["0000"]++;
        vector<int> ans;
        if(deadendSet.count("0000")){
            return -1;
        }

        while(!q.empty()){
            string currentCombination  = q.front().first;
            int level = q.front().second;
            q.pop();

            if(currentCombination == target){
                return level;
            }
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;
                    
                    if (vis.find(newCombination) == vis.end() && deadendSet.find(newCombination) == deadendSet.end()) {
                        vis[newCombination]++;
                        q.push({newCombination, level + 1});
                    }
                }
            }
        }
       
        return -1;
        
    }
};
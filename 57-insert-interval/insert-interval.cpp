class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            return {newInterval};
        }

        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        
        for(int i=1; i<intervals.size(); i++){
            
           int start = intervals[i][0];
           int end = ans.back()[1];
           if(end>=start){
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
           }
           else{
            ans.push_back({intervals[i][0],intervals[i][1]});
           }
        }
        return ans;
    }
};
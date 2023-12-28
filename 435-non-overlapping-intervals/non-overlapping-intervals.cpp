class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int answer = 0;
        int range = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=range){
                range = intervals[i][1];
            }
            else{
                answer++;
                range = min(range,intervals[i][1]);
            }
        }
        return answer;
    }
};
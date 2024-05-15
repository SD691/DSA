class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);

        int first = intervals[0][0];
        int last = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=1; i<intervals.size(); i++){
            if(last>=intervals[i][0]){
                first = min(first,intervals[i][0]);
                last = max(last,intervals[i][1]);
            }
            else{
                ans.push_back({first,last});
                first= intervals[i][0];
                last = intervals[i][1];
            }
        }
        ans.push_back({first,last});
        return ans;
    }
};
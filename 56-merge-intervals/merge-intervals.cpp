class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<int> p;
       vector<int> p1;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        p = intervals[0];
        for(int i=1; i<intervals.size(); i++){
            p1= intervals[i];
            if(p[1]>=p1[0]){
                p[1] = max(p[1],p1[1]);
            }
            else{
                ans.push_back(p);
                p = intervals[i];
               
            }
        }
        ans.push_back(p);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {{newInterval}};
        vector<vector<int>> vec;
        vector<int> temp;
       
        temp.push_back(newInterval[0]);
        temp.push_back(newInterval[1]);
        intervals.push_back(temp);
        temp.clear();
        sort(intervals.begin(),intervals.end());

        
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        vec.push_back(temp);
        temp.clear();



        for(int i=1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = vec.back()[1];

            if(end>=start){
                vec.back()[1]= max(vec.back()[1],intervals[i][1]);
            }
            else{
                
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                vec.push_back(temp);
                temp.clear();
            }
        }
        return vec;
    }
};
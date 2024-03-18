class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b ){
        return a.second < b.second;
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> temp;
        for(auto it: points){
            temp.push_back({it[0],it[1]});
        }

        sort(temp.begin(),temp.end(),comp);

        vector<pair<int,int>> ans;
        ans.push_back({temp[0].first,temp[0].second});
        int i = 1;
        while(i < temp.size()) {
            auto& it = temp[i];
            auto& last = ans.back();

            if (it.first <= last.second) {  // if current interval overlaps with previous
                last.first = max(last.first, it.first);
                last.second = min(last.second, it.second);
            } else {
                ans.push_back({it.first, it.second});  // new interval
            }
            i++;
        }

        return ans.size();
    }
};
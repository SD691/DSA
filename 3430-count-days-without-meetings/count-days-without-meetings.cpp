class Solution {
public:
    vector<pair<int,int>> merge(vector<vector<int>> &meetings){
        int last = meetings[0][1];
        vector<pair<int,int>> vec;
        
        vec.push_back({meetings[0][0],meetings[0][1]});
        for(int i=1; i<meetings.size(); i++){
            if(meetings[i][0]>vec.back().second){
                vec.push_back({meetings[i][0],meetings[i][1]});
            }
            else{
                vec.back().second = max(vec.back().second,meetings[i][1]);
            }
        }

        return vec;
    }

    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]<b[0]){
            return a[0]<b[0];
        }
        return a[1]<b[0];
    }
    int countDays(int days, vector<vector<int>>& meetings) {

        //edge case when   = 6 and meetings are like {1,5}

        if(meetings.size()==1){
            if(meetings[0][0]==1 && meetings[0][1] == days){
                return 0;
            }
            else{
                return (meetings[0][0]-1)+(days-meetings[0][1]);
            }
        }

        sort(meetings.begin(),meetings.end(),comp);
        vector<pair<int,int>> vec;
        vec = merge(meetings);


        if(vec.size()==1){
            return (vec[0].first-1)+days-(vec[0].second);
        }
        int ans = 0;
        ans += vec[0].first-1;
        for(int i=1; i<vec.size(); i++){
            ans += vec[i].first-vec[i-1].second-1;
        }
        int n = vec.size();
        ans += days-vec[n-1].second;
        return ans;
       
    }
};
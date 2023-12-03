class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count = 0;
        for(int i=0; i<points.size()-1; i++){
            int maxi = max(abs(points[i][0]-points[i+1][0]),abs(points[i][points[0].size()-1] - points[i+1][points[0].size()-1]));
           
       
            count = count + maxi;
            
        }
        return count;
    }
};
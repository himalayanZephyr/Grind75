#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
            int prev_right = output.back()[1];
            int current_left = intervals[i][0];
            int current_right = intervals[i][1];

            if(current_left <= prev_right){
                output.back()[1] = std::max(prev_right, current_right); 
            }
            else {
                output.push_back(intervals[i]);
            }
        }

        return output;
    }
};

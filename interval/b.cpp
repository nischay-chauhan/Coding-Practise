/* leetcode 57 Insert Interval */
#include "bits/stdc++.h"
using namespace std;

/* 
    1. sort the intervals
    2. merge the intervals
    3. insert the new interval

    case1: No overlapping case before the merge intervals and compare the ending point of intervals to starting point of newInterval
    case2: Overlapping case and merge the intervals
    case3: no overlapping of intervals after newInterval being merged

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(); // 5
        int i  = 0;

        //case1 : No overlapping case before the merge intervals and compare the ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        //case2 : Overlappong case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max(newInterval[1] , intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        //case3 : no overlapping of intervals after newInterval being merged
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<int> newInterval = {4,9};
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for(auto interval: ans){
        cout << interval[0] << " " << interval[1] << endl;
    }
}


/* leetcode 56 Merge Interval */
#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for(auto interval: intervals){
        if(ans.empty() || ans.back()[1] < interval[0]){
            ans.push_back(interval);
        }
        else{
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    for(auto interval: ans){
        cout << interval[0] << " " << interval[1] << endl;
    }
    return 0;
}

/* 
4. House Robber

Max sum without adjacent elements.
Example: [1,2,3,1] → 4
Concept: DP with skip
*/

#include "bits/stdc++.h"
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[n - 1];
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << rob(nums) << "\n";
}

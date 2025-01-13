/* Maximum Subarray Sum */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // dp[i] represents max sum ending at index i
        
        dp[0] = nums[0];
        int maxSum = dp[0];
        
       
        for(int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = solution.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;
    
    return 0;
}

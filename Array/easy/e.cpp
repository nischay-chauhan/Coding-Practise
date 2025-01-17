/* MAximum product Subarray 

Given an integer array, the task is to find the maximum product of any subarray.

*/
#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(max_so_far, min_so_far);
        }

        max_so_far = max(nums[i], max_so_far * nums[i]);
        min_so_far = min(nums[i], min_so_far * nums[i]);

        result = max(result, max_so_far);
    }

    return result;
}

int main(){
    vector<int> arr = {-2 , 6 , -3 , -10 , 0 , 2};
    cout << maxProductSubarray(arr);
}
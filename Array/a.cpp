/* Count Subarray sum Equals K
 */

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int>& arr, int k) {
    int n = arr.size();
    int start = 0, end = 0, currentSum = 0, count = 0;

   while(end < n){
        currentSum += arr[end];
        while(currentSum > k && start <= end){
            currentSum -= arr[start];
            start++;
        }
        if(currentSum == k){
            count++;
        }
        end++;
   }

    return count;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
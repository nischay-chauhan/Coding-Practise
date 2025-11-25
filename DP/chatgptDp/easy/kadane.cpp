/* 
8. Maximum Subarray (Kadane DP)

Max sum of contiguous array.
Example: [-2,1,-3,4] → 6
Concept: DP with running state
*/

#include "bits/stdc++.h"
using namespace std;

int kadane(vector<int>& arr){
    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int i = 0; i < arr.size(); i++){
        currentSum += arr[i];
        maxSum = max(maxSum , currentSum);
        if(currentSum < 0){
            currentSum = 0;
        }
    }
    return maxSum;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    arr = {2,3,-2,5};

    cout << kadane(arr) << "\n";
}
#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(vector<int> &arr, int n, int index, int currentSum, int targetSum) {
    if (index == n) {
        return (currentSum == targetSum) ? 1 : 0;
    }

    int include = countSubsequences(arr, n, index + 1, currentSum + arr[index], targetSum);

    int exclude = countSubsequences(arr, n, index + 1, currentSum, targetSum);

    return include + exclude;
}

int main() {
    vector<int> arr = {1, 2, 3, 4}; 
    int targetSum = 5;             

    cout << "Number of subsequences with sum " << targetSum << ": "
         << countSubsequences(arr, arr.size(), 0, 0, targetSum) << endl;

    return 0;
}

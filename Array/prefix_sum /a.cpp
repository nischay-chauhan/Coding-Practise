/* Range Sum Query (Static Array) 

Given an array arr[] of size n, preprocess it using prefix sums such that you can efficiently find the sum of elements between indices l and r (both inclusive) multiple times.

*/
#include <iostream>
#include <vector>
using namespace std;


vector<int> preprocessPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int rangeSum(const vector<int>& prefixSum, int l, int r) {
    if (l == 0) return prefixSum[r];
    return prefixSum[r] - prefixSum[l - 1];
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10};
    vector<int> prefixSum = preprocessPrefixSum(arr);

    int l = 1, r = 3; 
    cout << "Sum of range [" << l << ", " << r << "] is: " << rangeSum(prefixSum, l, r) << endl;

    return 0;
}

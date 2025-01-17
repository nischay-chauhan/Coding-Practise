/* Minimize the Heights

Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

 */
#include <bits/stdc++.h>
using namespace std;

int minimizeHeight(vector<int>& arr, int n, int k) {
    sort(arr.begin(), arr.end());
    int res = arr[n - 1] - arr[0];
    for (int i = 1; i < n; i++) {
        int small = min(arr[0] + k, arr[i] - k);
        int big = max(arr[n - 1] - k, arr[i - 1] + k);
        res = min(res, big - small);
    }
    return res;
}

int main(){
    int k = 2;
    vector<int> arr = {3, 9, 12, 16, 20};
    cout << minimizeHeight(arr , arr.size() , k);
}
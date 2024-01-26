/** You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.
Note :
Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArray(vector<int> &arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }

    return arr;
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 2, 0, 2, 1, 0};
    int n = arr.size();
    vector<int> arr1 = sortArray(arr, n);

    for (int i : arr1) {
        cout << i << " ";
    }

    return 0;
}

/** Dutch Flag Algorithm (DFA) is one of the most basic and important algorithms for arrays. It is used to segregate an array consisting of 3 numbers in linear time complexity.

The worst time complexity for DFA is O(n) and the space complexity for the algorithm is O(1). The problem statement is as follows: */
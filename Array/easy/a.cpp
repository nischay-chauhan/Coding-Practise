/* Second Largest Element in an Array  */
#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int>& arr){
    int n = arr.size();

    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i] < largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << secondLargestElement(arr);
}
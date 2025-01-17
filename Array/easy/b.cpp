/* Third Largest Element in the Array */
#include <bits/stdc++.h>
using namespace std;
int thirdLargestElement(vector<int>& arr){
    int n = arr.size();

    int largest = arr[0];
    int secondLargest = -1;
    int thirdLargest = -1; 

    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i] < largest && arr[i] > secondLargest){
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        }else if(arr[i] < secondLargest && arr[i] > thirdLargest){
            thirdLargest = arr[i];
        }
    }
    return thirdLargest;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << thirdLargestElement(arr);
}
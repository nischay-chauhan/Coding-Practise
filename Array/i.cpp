/* Majority Element II – Elements occurring more than ⌊N/3⌋ times
Last Updated : 23 Oct, 2024
Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times.
Note: The returned array of majority elements should be sorted.
 */
#include <bits/stdc++.h>
using namespace std;

int majorityElement2(vector<int> arr) {
    int n = arr.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (count1 == 0 && num2 != arr[i]) {
            num1 = arr[i];
            count1 = 1;
        } else if (count2 == 0 && num1 != arr[i]) {
            num2 = arr[i];
            count2 = 1;
        } else if (num1 == arr[i])
            count1++;
        else if (num2 == arr[i])
            count2++;
        else {
            count1--;
            count2--;
        }
    }
    int count3 = 0;
}

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 2, 2, 3, 3, 3};
   cout << majorityElement2(arr);
   cout << endl;

}
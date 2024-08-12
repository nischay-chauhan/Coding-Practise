/* largest subarray with sum k */
#include <bits/stdc++.h>
using namespace std;

int maxLenSubWithKSum(vector<int> arr, int k){

    int n = arr.size();
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxLen = 0;
    while(right < n){
        sum += arr[right];
        while(sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main(){
    vector<int> arr = {}
}
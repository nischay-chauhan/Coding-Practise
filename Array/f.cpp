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

int maxLen(vector<int> arr){
    unordered_set<int> s;
    int left = 0;
    int len = 0;
    for(int right = 0; right < arr.size(); right++){
        while(s.find(arr[right]) != s.end()){
            s.erase(arr[left]);
            left++;
        }
        s.insert(arr[right]);
        len = max(len, right - left + 1);
    }
    return len;
}

int main(){
    vector<int> arr = {1 ,2  , 3, 4 ,5  , 10 , 12};
    cout << maxLen(arr );
}
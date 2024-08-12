/* Length of Longest Substring without any Repeating Character */
#include<bits/stdc++.h>
using namespace std;

int findLongestSubstring(vector<int> arr){
    int n = arr.size();
    unordered_map<int, int> mp;
    int left = 0;
    int length = 0;
    int maxLength = 0;
    int right= 0 ;
    while(right < n){
        if(mp.find(arr[right]) != mp.end()){
            left = max(left, mp[arr[right]] + 1);
        }
        mp[arr[right]] = right;
        length = right - left + 1;
        maxLength = max(maxLength, length);
        right++;
    }
    return maxLength;
}

int main(){
    vector<int> arr = {1 , 2 , 3 , 4 , 5 , 6 , 5 , 5 , 5 , 5 ,6 ,6, 7};

    cout << findLongestSubstring(arr) << endl;


    return 0;
}
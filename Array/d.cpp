/* Count the number of subarrays with given xor K */
#include<bits/stdc++.h>
using namespace std;

#define console_log(x) std::cout << x << std::endl

int ksubarrayWithXor( vector<int> arr, int K){
    int n = arr.size();
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int currSum = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        currSum ^= arr[i];
        if (prefixSum.find(currSum ^ K) != prefixSum.end()) {
            count += prefixSum[currSum ^ K];
        }
        prefixSum[currSum]++;
    }
    
    return count;
}

int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    cout << ksubarrayWithXor(a, 6) << endl;
    return 0;
}
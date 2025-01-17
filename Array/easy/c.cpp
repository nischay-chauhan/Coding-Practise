/* Maximum product of a triplet in array */
#include <bits/stdc++.h>
using namespace std;

int maxTripletProduct(vector<int>& arr){
    int ans = 0;
    sort(arr.begin(), arr.end());
    ans = max(ans, arr[arr.size() - 1] * arr[arr.size() - 2] * arr[arr.size() - 3]);
    ans = max(ans, arr[0] * arr[1] * arr[arr.size() - 1]);
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << maxTripletProduct(arr);
}


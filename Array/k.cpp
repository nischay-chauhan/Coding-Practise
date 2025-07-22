#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1, res = 1;
        string prev = "";

        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] && prev != ">") {
                res = max(res, r - l + 1);
                r++;
                prev = ">";
            } else if (arr[r - 1] < arr[r] && prev != "<") {
                res = max(res, r - l + 1);
                r++;
                prev = "<";
            } else {
                r = (arr[r] == arr[r - 1]) ? r + 1 : r;
                l = r - 1;
                prev = "";
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {9,4,2,10,7,8,8,1,9};
    cout << "Test case 1: " << sol.maxTurbulenceSize(arr1) << endl; // Expected output: 5
    
    // Test case 2
    vector<int> arr2 = {4,8,12,16};
    cout << "Test case 2: " << sol.maxTurbulenceSize(arr2) << endl; // Expected output: 2
    
    // Test case 3
    vector<int> arr3 = {100};
    cout << "Test case 3: " << sol.maxTurbulenceSize(arr3) << endl; // Expected output: 1
    
    return 0;
}


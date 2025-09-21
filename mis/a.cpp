#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int tupleSameProduct(vector<int> &nums){
            unordered_map<int , int> pq;
            int n = nums.size();
            
            for(int i= 0 ; i < n ; i++){
                for(int j = i+1 ; j < n ; j++){
                    int product = nums[i] * nums[j];
                    pq[product]++;
                }
            }
            int count = 0;
            for(auto it : pq){
                int freq = it.second;
                count += freq * (freq-1) / 2;
            }
            return count;
        }
};


int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 3, 4, 6};
    cout << "Input: [2, 3, 4, 6]" << endl;
    cout << "Output: " << sol.tupleSameProduct(nums1) << endl;  // Expected: 8
    
    // Test case 2
    vector<int> nums2 = {1, 2, 4, 5, 10};
    cout << "\nInput: [1, 2, 4, 5, 10]" << endl;
    cout << "Output: " << sol.tupleSameProduct(nums2) << endl;  // Expected: 16
    
    // Test case 3 - Single pair
    vector<int> nums3 = {2, 3};
    cout << "\nInput: [2, 3]" << endl;
    cout << "Output: " << sol.tupleSameProduct(nums3) << endl;  // Expected: 0
    
    // Test case 4 - Empty input
    vector<int> nums4 = {};
    cout << "\nInput: []" << endl;
    cout << "Output: " << sol.tupleSameProduct(nums4) << endl;  // Expected: 0
    
    return 0;
}
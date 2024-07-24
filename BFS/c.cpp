#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

// Function to find all factors of a number
vector<int> findFactors(int num) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num / i) {
                factors.push_back(num / i);
            }
        }
    }
    return factors;
}

// Function to count minimum factor jumps
int minFactorJumps(const vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;

    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // pair of (current index, current jump count)
    
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {
        int currentIndex = q.front().first;
        int currentJumpCount = q.front().second;
        q.pop();

        vector<int> factors = findFactors(arr[currentIndex]);
        for (int factor : factors) {
            int nextIndex = currentIndex + factor;
            if (nextIndex == n - 1) {
                return currentJumpCount + 1;
            }
            if (nextIndex < n && !visited[nextIndex]) {
                visited[nextIndex] = true;
                q.push({nextIndex, currentJumpCount + 1});
            }
        }
    }

    return -1; // if no path found, which shouldn't happen in given constraints
}

int main() {
    vector<int> arr1 = {2, 8, 16, 55, 99, 100};
    cout << "Minimum jumps for arr1: " << minFactorJumps(arr1) << endl; // Output: 2

    vector<int> arr2 = {2, 4, 6};
    cout << "Minimum jumps for arr2: " << minFactorJumps(arr2) << endl; // Output: 1

    return 0;
}
